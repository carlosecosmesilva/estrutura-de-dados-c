// Implementação com listas encadeadas

#include "E:\GitHub\estrutura-de-dados-c\aulas\pilhas\Lista.c"
#include <limits.h>

typedef struct pilha
{
    TLista *topo;
} TPilha;

TPilha *inicializa()
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
    return 0;
}

int alteraTopo(TPilha *pilha, int novoElem)
{
    pilha->topo->info = novoElem;
    return 0;
}

void main()
{
    TPilha *pilha = inicializa();
    push(pilha, 5);
}