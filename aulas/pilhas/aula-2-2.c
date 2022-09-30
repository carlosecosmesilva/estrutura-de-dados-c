// Implementação com listas encadeadas

#include "aula-2-1.h"
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
    if (pilha_vazia(*pilha))
    {
        return -1;
    }
    return pilha->topo[pilha->topo--];
}

int peek(TPilha *pilha)
{
    if (pilha_vazia(*pilha))
    {
        return -1;
    }
    return pilha->topo[pilha->topo];
}

int main()
{
    TPilha *pilha = inicializa();
    push(pilha, 5);
    return 0;
}
