/* Retornar o maior elemento da árvore binária : int maior(TAB *a); */
#include "E:\GitHub\estrutura-de-dados-c\exercicios\lista-2\lista-2.c"

int maior(TAB *a)
{
    if (!a)
        return _MIN;

    int aux = a->info;
    int esq = maior(a->esq);
    int dir = maior(a->dir);
    return aux; /* fazer a comparação dos 3*/
}