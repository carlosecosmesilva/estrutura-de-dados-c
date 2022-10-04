#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    TLista *prox;
} TLista;

typedef struct fila
{
    TLista *inicio;
    TLista *fim;
} TFila;