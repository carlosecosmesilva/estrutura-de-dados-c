/* Testar se uma árvore é zigue - zague, isto é, todos os nós internos possuem exatamente uma sub - árvore vazia : int zz(TAB *a); */
#include <stdio.h>
#include <stdlib.h>

typedef struct ab
{
    int info;
    struct ab *esq, *dir;
} TAB;

int _MIN;

int zz(TAB *a)
{
    if (a->dir != NULL && a->esq != NULL)
    {
        exit(0);
    }
    if (a->esq != NULL)
        zz(a->esq);
    if (a->dir != NULL)
        zz(a->dir);
    return 1;
}