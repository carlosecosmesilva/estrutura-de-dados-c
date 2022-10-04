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

TFila *cria_fila(void)
{
    TFila *fila = (TFila *)malloc(sizeof(TFila));
    fila->inicio = NULL;
    fila->fim = NULL; // cria filas
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

void imprime_fila(TFila *fila)
{
    TLista *p;
    printf("\n----------------------------------");

    for (p = fila->inicio; p != NULL; p = p->prox)
    {
        printf("\n%d", p->info);
    }
    printf("\n----------------------------------");
}

void pushf(TFila *f1, int elem)
{ // insere novo elemento na fila
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL;
    if (!fila_vazia(f1))
    {
        f1->fim->prox = novo;
    }
    else
    {
        f1->inicio = novo;
    }
    f1->fim = novo;
}

int peekf(TFila *f1)
{ // retorna ultimo da fila equivalente ao topo
    return f1->fim->info;
}

void insere(TLista *p, TFila *f2)
{
    if (!fila_vazia(f2))
    {
        f2->fim->prox = p;
        p->prox = NULL;
    }
    else
    {
        p->prox = NULL;
        f2->inicio = p;
    }
    f2->fim = p;
    p->prox = NULL;
}

int popf(TFila *f1, TFila *f2)
{
    TFila *aux;
    TLista *p, *c = NULL;
    int resp;
    if (fila_vazia(f1))
    {
        printf("\nElemento nao encontrado");
        return 0;
    }
    else
    {
        for (p = f1->inicio; p != NULL; p = p->prox)
        {
            if (p->prox == NULL)
            { // se ultimo elemento, libera elemento
                resp = p->info;
                free(p);
                f1->inicio = NULL; // faz f1 apontar pra null e ficar vazia
                f1->fim = NULL;
                insere(c, f2); // insere elementos de f1 em f2
                break;
            }
            if (c != NULL)
            {
                insere(c, f2);
            }
            c = p; // acompanha p sempre um elemento atras
        }
    }

    // repassa f2 para f1

    f1->inicio = f2->inicio;
    f1->fim = f2->fim;
    f2->inicio = NULL;
    f2->fim = NULL;
    return resp;
}

int main()
{
    TFila *f1, *f2;
    int resp;

    f1 = cria_fila();
    f2 = cria_fila();

    pushf(f1, 10);
    pushf(f1, 20);
    pushf(f1, 30);
    pushf(f1, 40);
    pushf(f1, 50);

    imprime_fila(f1);
    imprime_fila(f2);

    printf("\nTopo: %d", peekf(f1));

    resp = popf(f1, f2);

    printf("\nExcluido: %d", resp);

    imprime_fila(f1);
}