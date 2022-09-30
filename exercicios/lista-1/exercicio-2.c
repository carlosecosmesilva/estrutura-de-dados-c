#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int data;
    TLista *prox;
} TLista;

typedef struct fila
{
    TLista *pilha1;
    TLista *pilha2;
} TFila;

void enfileirar(TFila *f, int x)
{
    push(&f->pilha1, x);
}

int desenfileirar(TFila *f)
{
    int x;

    if (f->pilha1 == NULL && f->pilha2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }

    if (f->pilha2 == NULL)
    {
        while (f->pilha1 != NULL)
        {
            x = pop(&f->pilha1);
            push(&f->pilha2, x);
        }
    }

    x = pop(&f->pilha2);
    return x;
}

void push(TLista **pTopo, int novaInfo)
{
    TLista *novoNo = (TLista *)malloc(sizeof(TLista));
    if (novoNo == NULL)
    {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }

    novoNo->data = novaInfo;
    novoNo->prox = (*pTopo);
    (*pTopo) = novoNo;
}

int pop(TLista **pTopo)
{
    int res;
    TLista *topo;

    if (*pTopo == NULL)
    {
        printf("Stack underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        topo = *pTopo;
        res = topo->data;
        *pTopo = topo->prox;
        free(topo);
        return res;
    }
}

int main()
{
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->pilha1 = NULL;
    f->pilha2 = NULL;
    enfila(f, 1);
    enfila(f, 2);
    enfila(f, 3);

    printf("%d ", desenfileirar(f));
    printf("%d ", desenfileirar(f));
    printf("%d ", desenfileirar(f));

    return 0;
}