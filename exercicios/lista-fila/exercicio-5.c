#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct TLista *prox;
} TLista;

typedef struct fila
{
    TLista *inicio;
    TLista *fim;
} TFila;

TLista *criarLista()
{
    return NULL;
}

TFila *criarFila()
{
    TFila *novo = (TFila *)malloc(sizeof(TFila));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

int fila_vazia(TFila *f)
{
    // f->inicio == NULL ? resultado = 1 : resultado = 0;
    if (f->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void altera_inicio(TFila *f, int elem)
{
    f->inicio->info = elem;
}


int retirarDaFila(TFila *f)
{
    if (fila_vazia(f))
    {
        exit(1);
    }
    int info = f->inicio->info; // remoção sempre no inicio
    TLista *aux = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
    return info;
}

void enfileirar(TFila *f, int i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    if (novo == NULL)
    {
        printf("Erro de alocação");
    }
    else
    {
        novo->info = i;
        novo->prox = NULL;
        if (f->inicio == NULL)
        {
            f->inicio = novo;
        }
        else
        {
            f->fim->prox = novo;
        }

        f->fim = novo;
    }
}

int desenfileirar(TFila *f)
{
    TLista *aux = f->inicio;
    int dado;

    if (aux != NULL)
    {
        f->inicio = aux->prox;
        aux->prox = NULL;
        dado = aux->info;
        free(aux);
    }
    else
    {
        printf("Fila vazia. \n");
        return;
    }
    return dado;
}

void imprimirFila(TFila *f)
{
    TLista *aux = f->inicio;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            printf("%d \n", aux->info);
            aux = aux->prox;
        }
    }
    else
    {
        printf("Fila vazia. \n");
        return;
    }
}

int main()
{
    TFila *f1 = criarFila();
    if (f1 == NULL)
    {
        printf("Erro de alocação!");
        ;
    }
    else
    {
        enfileirar(f1, 10);
        enfileirar(f1, 20);
        enfileirar(f1, 30);

        imprimirFila(f1);

        printf("Desenfileirando: %d \n", desenfileirar(f1));
        imprimirFila(f1);
        printf("Desenfileirando: %d \n", desenfileirar(f1));
        imprimirFila(f1);
        printf("Desenfileirando: %d \n", desenfileirar(f1));
        imprimirFila(f1);
    }

    return 0;
}
