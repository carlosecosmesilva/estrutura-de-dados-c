#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

typedef struct pilha
{
    TLista *topo;
} TPilha;

TPilha *cria_pilha()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void push(TPilha *pilha, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(TPilha *pilha)
{
    TLista *p;
    int removido;

    removido = pilha->topo->info;
    p = pilha->topo;
    pilha->topo = pilha->topo->prox;

    free(p);

    return removido;
}

int peek(TPilha *pilha)
{
    int elem;
    elem = pilha->topo->info;
    return elem;
}

void altera_topo(TPilha *pilha, int novo)
{
    pilha->topo->info = novo;
}

int main()
{
    TPilha *pilha = cria_pilha();
    int prim;

    push(pilha, 10);
    push(pilha, 9);
    push(pilha, 8);
    push(pilha, 7);
    push(pilha, 6);
    push(pilha, 5);

    prim = peek(pilha);
    printf("%d\n", prim);
    printf("---------------------------------------\n");

    altera_topo(pilha, 3);

    prim = peek(pilha);
    printf("%d\n", prim);
    printf("---------------------------------------\n");

    prim = pop(pilha);
    printf("%d\n", prim);
    printf("---------------------------------------\n");

    prim = peek(pilha);
    printf("%d\n", prim);
    printf("---------------------------------------\n");

    return 0;
}