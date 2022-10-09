/* Escreva uma função em C que, dadas duas árvores deste tipo, testa se estas árvores são iguais.A função retorna um se elas são iguais e zero, caso contrário.A função deve obedecer ao seguinte protótipo : int igual(TAB *a1, TAB *a2); */

#include "E:\GitHub\estrutura-de-dados-c\exercicios\lista-2\lista-2.c"

int igual(TAB *a1, TAB *a2)
{

    if (a1 == NULL && a2 == NULL)
    {
        return 1;
    }
    else if (a1 != NULL && a2 != NULL)
    {
        if (a1->info == a2->info && a1->esq == a2->esq && a1->dir == a2->dir)
        {
            igual(a1->esq, a2->esq);
            igual(a1->dir, a2->dir);
            return 0; /* muito brabo fi */
        }
    }
    exit(0);
}