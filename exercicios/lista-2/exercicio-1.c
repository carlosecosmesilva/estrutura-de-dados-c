#include "E:\GitHub\estrutura-de-dados-c\exercicios\lista-2\lista-2.c"

TAB *copia(TAB *a)
{

    if (a != NULL)
    {
        TAB *raizCopia = (TAB *)malloc(sizeof(TAB));
        raizCopia->info = a->info;
        raizCopia->esq = copia(a->esq);
        raizCopia->dir = copia(a->dir);
        return raizCopia;
    }
    else
        return NULL;
}