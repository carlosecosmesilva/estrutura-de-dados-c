#include "aula-2-1.h"

typedef struct pilha
{
    TLista *inicio;
    TLista *fim;
} TPilha;

void insere(TPilha *f, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; // inserção no fim da fila
    if (!fila_vazia(f))
    {
        f->fim->prox = novo;
    }
    else
    {
        f->inicio = novo;
    }
    f->fim = novo; // elt. novo é o novo fim da fila
}
int fila_vazia(TPilha *f)
{
    if (f->inicio == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int retira(TPilha *f)
{
    if (fila_vazia(f))
    {
        exit(1);
    }
    int info = f->inicio->info;
    TLista *aux = f->inicio;
    f->inicio = f->inicio->prox;
    // se elemento removido era o único da fila
    // faz fim apontar para NULL também
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
    return info;
}