#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int info;
} TPilha;

int base, lim, topo;

void inicializarPilha(int *base, int *lim, int *topo)
{
    *base = 0;
    *lim = 9;
    *topo = -1;
} // uso de ponteiros para permitir alteração das variáveis

int push(TPilha *pilha, int lim, int *topo, int info)
{
    if (pilha_cheia(lim, *topo))
    {
        return -1; // pilha estando cheia, inserção se torna inválida
    }
    else
    {
        // faz a inserção
        *topo = *topo + 1;
        pilha[*topo].info = info;
        return info; // retorna elemento inserido
    }
}

int pilha_cheia(int lim, int topo)
{
    if (topo == lim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(TPilha *pilha, int base, int *topo)
{
    if (pilha_vazia(base, *topo))
    {
        return -1; // se a pilha vazia a remoção é inválida.
    }
    else
    {
        // faz a remoção
        int info = pilha[*topo].info;
        *topo = *topo = 1;
        return info; // retorna o elemento removido
    }
}

int pilha_vazia(int base, int topo)
{
    if (topo < base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek(TPilha *pilha, int base, int *topo)
{
    if (pilha_vazia(base, *topo))
    {
        return 1; // pilha vazia
    }
    else
    {
        // faz a consulta
        return pilha[*topo].info;
    }
}

int main()
{
    TPilha pilha[10];
    inicializarPilha(&base, &lim, &topo);
    return 0;
}
