#include <stdio.h>
#include <stdlib.h>

typedef TCliente *Hash;
typedef struct cliente
{
    int cod;
    char nome[30];
    int prox;
    int liberado; // 0 = OCUPADO, 1 = LIBERADO
} TCliente;

typedef struct dados
{
    int key;
    struct TipoItem *prox;
} TDados;

TCliente *aloca(int cod, int status, int prox)
{
    TCliente *novo = (TCliente *)malloc(sizeof(TCliente));
    novo->cod = cod;
    novo->liberado = status;
    novo->prox = prox;
    return novo;
}

void inicializa(Hash *tab, int m)
{
    /* m é o tamanho da tabela */
    int i;
    for (i = 0; i < m; i++)
    {
        tab[i] = aloca(-1, 1, -1);
    }
}

void insereHash(Hash tab, int num)
{
    int i = 0;
    int chave = funcaoHash(num);
    TDados *aux = tab[chave];
    while (aux != NULL)
    {
        if (aux->key == num)
        {
            break;
        }
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        aux = (TDados *)malloc(sizeof(TDados));
        aux->key = num;
        aux->prox = tab[chave];
        tab[chave] = aux;
    }
}

int main()
{
    
    return 0;
}
