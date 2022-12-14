#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    TLista *prox;
} TLista;

TLista *criar_lista()
{
    return NULL;
}

TLista *inserir(TLista *inicio, int info)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->prox = inicio;
    novo->info = info;
    return novo;
}

TLista inserir_fim(TLista *li, int i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista *p = li;
    if (p == NULL)
    {
        li = novo;
    }
    else
    {
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novo;
    }
    return;
}

void imprimirLista(TLista *li)
{
    while (li != NULL)
    {
        printf(" %d ", li->info);
        li = li->prox;
    }
}

TLista *retirar(TLista *inicio)
{
    TLista *aux;
    aux = inicio;
    inicio = inicio->prox;
    free(aux);
    return inicio;
}

TLista *inverterLista(TLista *inicio)
{
    int aux;
    TLista *p;
    TLista *novaLista = criar_lista();

    for (p = inicio; p != NULL; p->prox)
    {
        novaLista = inserir(novaLista, p->info);
    }
    p = inicio;

    while (p != NULL)
    {
        inicio = retirar(inicio);
        p = inicio;
    }

    return novaLista;
}

TLista *excluir(TLista *li, int elem)
{
    TLista *p;
    TLista *c;

    if (li->prox == NULL)
    {
        return NULL;
    }
    if (li->info == elem)
    {
        p = li; // cria auxiliar para poder liberar memoria e nao quebrar a lista
        li = p->prox;
        printf("Elemento encontrado: %d\n", elem);
        printf("--------------------------------------------\n");
    }
    else
    {
        for (p = li; p != NULL; p = p->prox)
        {
            if (p->info == elem)
            {
                c->prox = p->prox; // c usado para percorrer a lista sempre um elemento antes de p
                printf("Elemento encontrado: %d\n", elem);
                printf("--------------------------------------------\n");
                break;
            }
            c = p;
        }
    }
    free(p);
    return li;
}

TLista *removerDaLista(TLista *inicio, int remover)
{
    TLista *p;
    TLista *nova = criar_lista();
    for (p = inicio; p != NULL; p = p->prox)
    {
        if (p->info != remover)
        {
            nova = inserir(nova, p->info);
        }
    }
    p = inicio;
    while (p != NULL)
    {
        inicio = retirar(inicio);
        p = inicio;
    }
    return nova;
}

TLista *trocarAnterior(TLista *inicio, int x)
{
    TLista *p;
    TLista *ant, *atual, *prox;

    for (p = inicio; p->prox != NULL; p = p->prox)
    {
        ant = p;
        atual = p->prox;
        prox = atual->prox;
        if (atual->info == x)
        {
            int aux = ant->info;
            ant->info = prox->info;
            prox->info = aux;
        }
    }
    return inicio;
}

TLista *ordenar(TLista *li)
{
    TLista *q;
    TLista *t;
    for (t = li; t->prox != NULL; t = t->prox)
    {
        for (q = li; q->prox != NULL; q = q->prox)
        {
            if (q->info > q->prox->info)
            {
                int aux = q->info;       // cria um auxiliar para salvar o valor atual do nó.
                q->info = q->prox->info; // altera valor atual para o prox.
                q->prox->info = aux;     // coloca a informação do próx como atual.
            }
        }
    }
    return li;
}

TLista *merge(TLista *l1, TLista *l2)
{
    TLista *novaLista;
    TLista *p;
    TLista *aux;
    int podeInserir;
    novaLista = criar_lista();

    for (p = l1; p != NULL; p->prox)
    {
        podeInserir = 1;
        for (aux = l2; aux != NULL; aux->prox)
        {
            if (p->info == aux->info)
            {
                podeInserir = 0;
                break;
            }
        }
        if (podeInserir)
        {
            inserir(novaLista, p->info);
        }
    }
    for (aux = l2; aux != NULL; aux = aux->prox)
    {
        inserir(novaLista, aux->info);
    }
    return novaLista;
}

TLista *insere_fim_lista(TLista *li, TLista *l2)
{
    TLista *p = li;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = l2;

    return li;
}

TLista *inverter_mn(TLista *l, int n, int m)
{
    TLista *p, *p2;
    TLista *listaInvertida = criaLista();
    TLista *final = criaLista();
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == n)
        {
            for (p2 = p; p2->prox->info != m; p2 = p2->prox)
            {
                listaInvertida = insereLista(listaInvertida, p2->prox->info);
            }
            break;
        }
    }
    for (p = l; p->info == n; p = p->prox)
    {
        final = insereFim(final, p->info);
    }
    for (p2 = final; p2 != NULL; p2 = p2->prox)
    {
        final = insereFim(final, p2->info);
    }
    for (p = l; p == m; p = p->prox)
    {
        for (p; p != NULL; p = p->prox)
        {
            final = insereFim(final, p->prox);
        }
    }

    return final;
}

int main()
{

    return 0;
}