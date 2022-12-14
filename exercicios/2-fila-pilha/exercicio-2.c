#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    TLista *prox;
} TLista;

typedef struct pilha
{
    TLista *topo;
} TPilha;

void push_pilha(TPilha *pilha, int info)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = info;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop_pilha(TPilha *pilha)
{
    TLista *aux;
    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    int x = aux->info;
    free(aux);
    return x;
}

void ret_como_fila_por_pilha(TPilha *pilha)
{
    if (pilha->topo->prox == NULL)
    {
        TLista *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
    else
    {
        TLista *p;
        TPilha *auxPilha = inicializa();
        while (pilha->topo->prox != NULL)
        {
            push(auxPilha, pop(pilha));
        }
        pop(pilha);
        while (auxPilha->topo != NULL)
        {
            push(pilha, pop(auxPilha));
        }
        free(auxPilha);
    }
}

int main()
{
    
    return 0;
}
