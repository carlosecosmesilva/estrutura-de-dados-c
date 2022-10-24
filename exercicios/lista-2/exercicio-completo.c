#include <stdio.h>
#include <stdlib.h>

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

// Falta testar

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

main()
{
    TAB *arvore1;
    arvore1 = insere(2);
    arvore1->dir = insere(3);
    arvore1->dir->dir = insere(4);
    arvore1->dir->dir->esq = insere(5);
    int resultado = verificarSeArvoreZigZag(arvore1);
    printf("%d\n", resultado);
}
