#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    TLista *prox;
} TLista;

typedef struct arvore
{
    int info;
    struct arvore *esq, *dir;
} TAB;

TAB *insere(int info)
{
    TAB *novo = (TAB *)malloc(sizeof(TAB));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TAB *copia(TAB *a)
{
    if (a != NULL)
    {
        TAB *arvoreCopia = (TAB *)malloc(sizeof(TAB));
        arvoreCopia->info = a->info;
        arvoreCopia->esq = copia(a->esq);
        arvoreCopia->dir = copia(a->dir);
        return arvoreCopia;
    }
    return NULL;
}

TAB *espelho(TAB *a)
{
    if (a != NULL)
    {
        TAB *arvoreEspelho = (TAB *)malloc(sizeof(TAB));
        arvoreEspelho->info = a->info;
        arvoreEspelho->esq = espelho(a->dir);
        arvoreEspelho->dir = espelho(a->esq);
        return arvoreEspelho;
    }
    return NULL;
}

int verificarSeArvoreIgual(TAB *a1, TAB *a2)
{
    if (a1 != NULL && a2 != NULL)
    {
        if (a1->info == a2->info)
        {
            return (verificarSeArvoreIgual(a1->esq, a2->esq) && verificarSeArvoreIgual(a1->dir, a2->dir));
        }
        else
        {
            return 0;
        }
    }
    else if (a1 == NULL && a2 == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int maiorVal = NULL;

int maior(TAB *a)
{
    if (a == NULL)
    {
        return NULL;
    }
    int no = a->info;
    int esq = maior(a->esq);
    int dir = maior(a->dir);
    if (dir > no)
    {
        no = dir;
    }
    else if (esq > no)
    {
        no = esq;
    }
    return no;
}

int verificarSeArvoreZigZag(TAB *a)
{

    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if (verificarSeArvoreZigZag(a->esq) && !verificarSeArvoreZigZag(a->dir))
            return 1;
        if (!verificarSeArvoreZigZag(a->esq) && verificarSeArvoreZigZag(a->dir))
            return 1;
        if (!verificarSeArvoreZigZag(a->esq) && !verificarSeArvoreZigZag(a->dir))
            return 1;
        else
            return 0;
    }
}

TAB *retiraPares(TAB *arv)
{
    if (arv != NULL)
    {
        if (arv->info % 2 == 0)
        {
            TAB *aux;
            if (arv->esq != NULL && arv->dir == NULL)
            {
                aux = arv;
                arv = arv->esq;
                free(aux);
                retiraPares(arv);
            }
            if (arv->esq == NULL && arv->dir != NULL)
            {
                aux = arv;
                arv = arv->dir;
                free(aux);
                retiraPares(arv);
            }
        }
        else
        {
            retiraPares(arv->esq);
            retiraPares(arv->dir);
        }
    }
}

TLista *ancestrais(TAB *no, int elem)
{
    if (!busca(no, elem))
        return NULL;
    TLista *ListaAnc = cria_lista();
    if (no)
    {
        if (elem < no->info)
        {
            ListaAnc = insere_fim(ListaAnc, no->info);
            ListaAnc->prox = ancestrais(no->esq, elem);
        }

        else if (elem > no->info)
        {
            ListaAnc = insere_fim(ListaAnc, no->info);
            ListaAnc->prox = ancestrais(no->dir, elem);
        }

        else if (elem == no->info)
        {
            return ListaAnc;
        }
    }
    return ListaAnc;
}

TLista *menores(TAB *no, int n)
{

    TLista *ListaMen = cria_lista();

    if (no)
    {
        if (no->info < n)
        {
            ListaMen->prox = insere_fim(ListaMen, no->info);
        }
        else
        {
            ListaMen->prox = insere_fim(ListaMen, -1);
        }

        if (no->dir)
        {
            ListaMen->prox = menores(no->dir, n);
        }
        else if (ListaMen->prox && no->esq)
        {
            ListaMen->prox->prox = menores(no->esq, n);
        }
        else if (no->esq)
        {
            ListaMen->prox = menores(no->esq, n);
        }

        return ListaMen;
    }
}

int main()
{
    TAB *arvore1;
    arvore1 = insere(2);
    arvore1->dir = insere(3);
    arvore1->dir->dir = insere(4);
    arvore1->dir->dir->esq = insere(5);
    int resultado = verificarSeArvoreZigZag(arvore1);
    printf("%d\n", resultado);
}