#include <stdio.h>
#include <stdlib.h>

typedef struct lista // struct da lista
{
    int info;
    TLista *prox;
} TLista;

typedef struct pilha
{
    TLista *topo;
} TPilha;

TPilha *criarPilha()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(TPilha *p, char elem) // Empilhar
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(TPilha *p)
{
    if (!p)
    {
        exit(1);
    }

    int removido;
    TLista *aux = (TLista *)malloc(sizeof(TLista));
    removido = p->topo->info;
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    return removido;
}

void print(TPilha *p)
{
    TLista *aux;
    aux = p->topo;
    while (aux)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

int min(TPilha *p) {
    int auxMin = __INT_MAX__;
    
    while (p->topo)
    {
        if (p->topo < min)
        {
            auxMin = p->topo;
        }
        pop(p);
    }
    return auxMin;
}

int main()
{

    return 0;
}
