#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore
{
    char info;
    TAB *esq;
    TAB *dir;
} TAB;

TAB *criarArvore(char c)
{
    TAB *novo = (TAB *)malloc(sizeof(TAB));

    novo->info = c;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

void imprimirArvore(TAB *a, int tab)
{
    for (int i = 0; i < tab; i++)
    {
        printf("-");
    }
    if (a != NULL)
    {
        printf("%c \n", a->info);
        imprimirArvore(a->esq, tab + 2);
        printf("\n");
        imprimirArvore(a->dir, tab + 2);
    }
}

void profundidade(TAB *a)
{
    if (a != NULL)
    {
        printf("%c \n", a->info);
        profundidade(a->esq);
        profundidade(a->dir);
    }
}

void simetrica(TAB *a)
{
    if (a != NULL)
    {
        simetrica(a->esq);
        printf("%c\n", a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TAB *a)
{
    if (a != NULL)
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c \n", a->info);
    }
}

int verificarAltura(TAB *a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        int esq = 1 + verificarAltura(a->esq);
        int dir = 1 + verificarAltura(a->dir);
        if (esq > dir)
        {
            return esq;
        }
        else if (esq < dir)
        {
            return dir;
        }
        else
        {
            return esq;
        }
    }
}

int verificarQtdNo(TAB *a)
{
    // int res;
    // a == NULL ? res = 0 : res = 1 + verificarQtdNo(a->esq) + verificarQtdNo(a->dir);
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + verificarQtdNo(a->esq) + verificarQtdNo(a->dir);
    }
}

int verificarTABCheia(TAB *a, int qtdNo, int alt)
{
    int calculaNos = 0;
    for (int i = 0; i < alt; i++)
    {
        calculaNos = pow(2, i);
    }
    if (calculaNos == qtdNo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

TAB *espelho(TAB *a)
{
    if (a != NULL)
    {
        TAB *arvoreEspelho = (TAB *)malloc(sizeof(TAB));
        arvoreEspelho->info = a->info;
        arvoreEspelho->esq = espelho(a->dir);
        arvoreEspelho->dir = espelho(a->esq);
        return arvoreEspelho;
    }
    return NULL;
}