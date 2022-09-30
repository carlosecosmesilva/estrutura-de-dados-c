#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

TLista *criarLista(void)
{
    return NULL;
}

TLista *inserirInicio(TLista *li, int i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

void imprimirLista(TLista *li)
{
    TLista *p;
    for (p = li; p != NULL; p = p->prox)
    {
        printf("info = %d\n", p->info);
    }
}

TLista *inserirFim(TLista *li, int i)
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

    return li;
}

TLista *inserirOrdenado(TLista *li, int i)
{
    TLista *novo;
    novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    TLista *p = li; /* ponteiro para percorrer a lista */
    if (p == NULL)  /* lista vazia -- insere no inicio */
    {
        novo->prox = NULL;
        li = novo;
    }
    else if (p->info > i)
    { /* insere no início da lista */
        novo->prox = li;
        li = novo;
    }
    else
    { /* procura posição de inserção */
        while (p->prox != NULL && p->prox->info < i)
        {
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }

    return li;
}

TLista *inserirFimRecursivo(TLista *li, int i)
{
    if (li == NULL || li->prox == NULL)
    {
        TLista *novo = (TLista *)malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = NULL;
        if (li == NULL)
        {
            li = novo;
        }
        else
        {

            li->prox = novo;
        }
    }
    else
    {

        insere_fim_recursivo(li->prox, i);
    }
    return li;
}

TLista *inserirOrdenadoRecursivo(TLista *li, int i)
{
    if (li == NULL || li->prox == NULL)
    { // lista vazia
        TLista *novo = (TLista *)malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = NULL;
        if (li == NULL)
        {

            li = novo;
        }
        else
        { /* inserir no meio da lista */
            if (li->info > i)
            {
                novo->prox = li;
                li = novo;
            }
            else
            {

                li->prox = novo;
            }
        }
    }
    else
    {
        if (li->info > i)
        {
            TLista *novo = (TLista *)malloc(sizeof(TLista));
            novo->info = i;
            novo->prox = li;
            li = novo;
        }
        else
        {

            li->prox = insere_ordenado_recursivo(li->prox, i);
        }
    }
    return li;
}

TLista *excluirLista(TLista *li, int i)
{
    TLista *ant = NULL; /* ponteiro para elemento anterior */
    TLista *p = li;      /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != i)
    {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
    {

        return li; /* não achou: retorna lista original */
    }
    /* retira elemento */
    if (ant == NULL)
    {
        /* retira elemento do inicio */
        li = p->prox;
    }
    else
    {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return li;
}

TLista *alterarLista(TLista *li, int vantigo, int vnovo)
{
    
}

int main()
{

    return 0;
}
