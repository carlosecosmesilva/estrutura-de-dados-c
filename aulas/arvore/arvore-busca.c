#include <stdio.h>
#include <stdlib.h>

typedef struct arvorebusca
{
    char info;
    int chave;
    TAB *esq;
    TAB *dir;
} TAB;

TAB *busca(TAB *no, int chave)
{
    if (no == NULL)
    {
        return NULL;
    }
    else if (no->chave == chave)
    {
        return no;
    }
    else if (no->chave > chave)
    {
        busca(no->esq, chave);
    }
    else
    {
        busca(no->dir, chave);
    }
}

TAB *insere(TAB *no, int chave)
{
    if (no == NULL)
    {
        TAB *novo = (TAB *)malloc(sizeof(TAB));
        novo->chave = chave;
        novo->dir = NULL;
        novo->esq = NULL;
    }
    else if (chave < no->chave)
    {
        insere(no->esq, chave);
    }
    else if (chave > no->chave)
    {
        insere(no->dir, chave);
    }
    else
    {
        printf("Inserção inválida, chave já existe!");
        exit(1);
    }
    return no;
}

void criarArvoreBalanceada(TAB *raiz, int v[], int inicio, int fim)
{
    if (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        raiz = insere(raiz, v[meio]);
        criarArvoreBalanceada(raiz, v, inicio, meio - 1);
        criarArvoreBalanceada(raiz, v, meio + 1, fim);
    }
}

int main()
{

    return 0;
}
