#include <stdio.h>
#include <stdlib.h>

typedef struct lista // struct da lista
{
    char info;
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

char *remover_duplicatas(char *s){
    TPilha *p = criarPilha();
    int i = 0;

    while (s[i] != "\0")
    {
        push(p, s[i]);
        if (p->topo->info == p->topo->prox)
        {
            pop(p);
            pop(p);
        }
        
    }
    TPilha * pilhaAux = criarPilha();
    while (p->topo != NULL)
    {
        push(pilhaAux, p->topo);
    }
    while (pilhaAux->topo != NULL)
    {
        printf("%c", pop(pilhaAux));
    }
    return s;
}

int main()
{

    return 0;
}
