#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

typedef struct fila
{
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *cria_fila()
{
    TFila *fila = (TFila *)malloc(sizeof(TFila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int fila_vazia(TFila *fila)
{
    if (fila->inicio == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void insere(TFila *fila, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista)); // inserção sempre no fim
    novo->info = elem;
    novo->prox = NULL;
    if (!fila_vazia(fila))
    {
        fila->fim->prox = novo;
    }
    else
    {
        fila->inicio = novo;
    }
    fila->fim = novo;
}

int retira(TFila *fila)
{
    if (fila_vazia(fila))
    {
        exit(1);
    }
    int info = fila->inicio->info; // remoção sempre no inicio

    TLista *aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }
    free(aux);
    return info;
}

void altera_inicio(TFila *fila, int elem)
{
    fila->inicio->info = elem;
}

void imprime_fila(TFila *fila)
{
    TLista *p;
    printf("----------------------------------\n");

    for (p = fila->inicio; p != NULL; p = p->prox)
    {
        printf("%d\n", p->info);
    }
    printf("----------------------------------\n");
}

int main()
{
    TFila *fila = cria_fila();
    int a;

    insere(fila, 10);
    insere(fila, 20);
    insere(fila, 30);
    insere(fila, 40);

    imprime_fila(fila);

    a = retira(fila);

    imprime_fila(fila);

    altera_inicio(fila, 400);

    imprime_fila(fila);
    printf("Retirado: %d", a);

    return 0;
}