#include <stdio.h>
#include <stdlib.h>

#define filaVazia 0xdeadbeef
#define MAX 128

typedef struct fila
{
    int *pInfo;
    int ant, prox, cont, max;
} TFila;

int verificarFilaVazia(TFila *f)
{
    return contarNaFila(f);
}

int contarNaFila(TFila *f)
{
    return f->cont;
}

int retornarFilaVazia(TFila *f)
{
    return (f->cont == 0);
}

int inserirNaFila(TFila *f, int v)
{
    if (f->cont == f->max)
    {
        return;
    }
    f->pInfo = (f->ant + 1) % f->max;
    f->ant[f->pInfo] = f;
    f->cont++;
}

int removerDaFila(TFila *f)
{
    int auxRemocao;

    if (f->cont == 0)
    {
        return filaVazia;
    }

    f->prox = (f->prox + 1) % f->max;
    auxRemocao = f->pInfo[f->prox];
    f->cont--;

    return filaVazia;
}

void imprimirFila(TFila *f)
{
    int i = (f->prox + 1) % f->max, elemento = contarNaFila(f);

    while (elemento--)
    {
        printf("[%d], ", f->pInfo[i]);
        i = (i >= f->max) ? 0 : (i + 1);
    }
}

void push(TFila *f, int v)
{
    inserirNaFila(f, v);
}

int pop(TFila *f)
{
    int i, n = contarNaFila(f);
    int elementoRemovido;

    for (i = 0; i < (n - 1); i++)
    {
        elementoRemovido = removerDaFila(f);
        inserirNaFila(f, elementoRemovido);
    }
    elementoRemovido = removerDaFila(f);

    return elementoRemovido;
}

TFila *alocarNaFila(int n)
{
    TFila *pFila;
    pFila = malloc(sizeof(TFila));

    if (pFila == NULL)
    {
        return NULL;
    }
    pFila->max = n;

    pFila->pInfo = malloc(sizeof(int) * n);
    pFila->ant = n - 1;
    pFila->prox = n - 1;

    return pFila;
}

int main(void)
{
    TFila *f;
    int x, select;
    f = queue_allocate(MAX);

    do
    {
        printf("\n[1] Push\n[2] Pop\n[0] Exit");
        printf("\nEscolha: ");
        scanf(" %d", &select);

        switch (select)
        {
        case 1:
            printf("\nEntre com o valor de Push:");
            scanf(" %d", &x);
            stack_push(f, x);

            printf("\n\n__________________________\nFila Atual:\n");

            queue_display(f);
            printf("\n\nPushed Value: %d", x);

            printf("\n__________________________\n");
            break;

        case 2:
            x = stack_pop(f);

            printf("\n\n\n\n__________________________\nFila Atual:\n");

            queue_display(f);
            if (x == filaVazia)
                printf("\n\nNenhum valor removido");
            else
                printf("\n\nPopped Value: %d", x);

            printf("\n__________________________\n");
            break;

        case 0:
            printf("\nSaída.\n");
            return 0;

        default:
            printf("\nSaída.\n");
            return 0;
        }
    } while (1);

    return 0;
}