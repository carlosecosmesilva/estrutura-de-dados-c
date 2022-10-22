#include <stdio.h>
#include <stdlib.h>

/* Questão 1, uma pilha por meio de duas filas */

typedef struct lista
{
    int info;
    TLista *prox;
} TLista;

TLista *criaLista()
{
    return NULL;
}

typedef struct fila
{
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *criafila()
{
    TFila *novo = (TFila *)malloc(sizeof(TFila));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

void insereFila(TFila *f, int i)
{
    TLista *novo = (TFila *)malloc(sizeof(TFila));
    novo->info = NULL;
    if (f == NULL)
        f->inicio = novo;
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int retira(TFila *f)
{
    if (f == NULL)
        exit(1);
    int info;
    TLista *aux = (TLista *)malloc(sizeof(TLista));
    info = f->inicio->info;
    aux = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(aux);
    return info;
}

void pegaTopo(TFila *f)
{
    int resultado;
    if (f->fim == f->inicio)
    {
        resultado = retira(f);
    }
    else
    {
        TFila *filaAux = (TFila *)malloc(sizeof(TFila));
        while (f->inicio->prox != NULL)
        {
            insereFila(filaAux, retira(f));
        }
        resultado = retira(f);
        while (filaAux->inicio != NULL)
        {
            insereFila(f, retira(filaAux));
        }
    }
    printf("%d\n", resultado);
}

void main()
{
    TFila *f = criafila();
    insereFila(f, 1);
    insereFila(f, 2);
    insereFila(f, 3);
    pegaTopo(f);
}