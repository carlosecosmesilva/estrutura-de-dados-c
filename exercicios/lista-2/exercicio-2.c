/* Escreva uma função em C que faz o espelho de uma árvore binária (o que está
à esquerda na árvore original, estará a direita no espelho, e vice-versa): */

#include "E:\GitHub\estrutura-de-dados-c\exercicios\lista-2\lista-2.c"

TAB *espelho(TAB *a)
{

    if (a != NULL)
    {
        TAB *raizEspelho = (TAB *)malloc(sizeof(TAB));
        raizEspelho->info = a->info;
        raizEspelho->esq = espelho(a->dir);
        raizEspelho->dir = espelho(a->esq);
        return raizEspelho;
    }
    return NULL;
}