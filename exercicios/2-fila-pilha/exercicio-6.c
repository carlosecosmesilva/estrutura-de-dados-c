#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    int topo;
    unsigned tamanho;
    char *sPalavra;
} TPilha;

TPilha *criarPilha(unsigned tamanho)
{
    TPilha *novo = (TPilha *)malloc(sizeof(TPilha));
    novo->tamanho = tamanho;
    novo->topo = -1;
    novo->sPalavra = (char *)malloc(novo->tamanho * sizeof(char));
    return novo;
}

int _MIN;

int verificarSePilhaEstaCheia(TPilha *novo)
{
    return novo->topo == novo->tamanho - 1;
}

int verificarSePilhaEstaVazia(TPilha *novo)
{
    return novo->topo == -1;
}

void push(TPilha *novo, char item)
{
    if (verificarSePilhaEstaCheia(novo))
    {
        return 1;
    }
    else
    {
        novo->sPalavra[++novo->topo] = item;
    }
}

char pop(TPilha *novo)
{
    if (verificarSePilhaEstaVazia(novo))
    {
        return _MIN;
    }
    return novo->sPalavra[novo->topo--];
}

void removerCaracter(char *vPalavra, char charARemover)
{
    int i, j;
    int len = strlen(vPalavra);
    for (i = 0; i < len; i++)
    {
        if (vPalavra[i] == charARemover)
        {
            for (j = i; j < len; j++)
            {
                vPalavra[j] = vPalavra[j + 1];
            }
            len--;
            i--;
        }
    }
}

void inverterPalavra(char vPalavra[])
{
    int n = strlen(vPalavra);
    TPilha *novo = criarPilha(n);
    int i;

    for (i = 0; i < n; i++)
    {
        push(novo, vPalavra[i]);
    }

    for (i = 0; i < n; i++)
    {
        vPalavra[i] = pop(novo);
    }
}

int main()
{
    char vPalavra[] = "amor";

    inverterPalavra(vPalavra);

    printf("Palavra invertida: %s", vPalavra);

    return 0;
}
