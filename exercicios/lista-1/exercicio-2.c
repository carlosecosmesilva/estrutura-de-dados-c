#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int info;
    TPilha *prox;
} TFila;

typedef struct pilha
{
    TFila *inicio;
    TFila *fim;
} TPilha;