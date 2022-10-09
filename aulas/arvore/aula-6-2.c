/* Árvore
o primeiro nó é a raiz.
nós podem ser pais e filhos e nós de mesmo nível são irmãos
se x pertence a subarvore z, dizemos que x é descendente de v e v é ancestral de x
grau de um nó: é dado pela qunatidade de filhos de um nó. Ex: x tem 3 filhos, ou seja, x tem grau 3
Nó interno: nó com pelo menos um filho
nó folha: nó com grau igual a zero
caminho: uma sequência de nós consecutivos distintos entre dois nós
comprimento do caminho: ligações entre os nós
Nivel: contagem da raiz até a folha mais distante
altura: contagem da folha de maior nível até a raiz
Árvores binárias:
Estritamente Binária: 0 ou 2 filhos
Binária completa: Subárvores vazias apeas no último ou penúltimo nível
Binária cheia: subárvores vazias somente no último nível
Zigue Zague:Nós internos com uma subárvore vazia*/

/* Caminhamento de uma árvore: cada nó deve ser visitado apenas uma vez

Pré-Ordem(Profundidade): visita a raiz, visita a subarvore esquerda, visita a subarvore direita
Largura: visita é feita por nível, da esquerda para a direita
Ordem simétrica: percorre a subarvore da esquerda, visita a raiz, percorre a subarvore da direita
Pós-Ordem: percorre a subarvore da esquerda, percorre a subarvore da direita, visita a raiz*/

// Implementação de árvores binárias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// representação dos nós de a
typedef struct noA
{
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

// Criar nó
TNoA *criaNo(char ch)
{
    TNoA *novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
// Imprimir a Árvore

void imprime(TNoA *nodo, int TNoA)
{
    for (int i = 0; i < TNoA; i++)
    {
        printf("-");
    }
    if (nodo != NULL)
    {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, TNoA + 2);
        printf("\n");
        imprime(nodo->dir, TNoA + 2);
    }
    else
        printf("vazio");
}

// caminhamentos

void profundidade(TNoA *a)
{
    if (a != NULL)
    {
        printf("%c\n", a->info);
        profundidade(a->esq);
        profundidade(a->dir);
    }
}

void simetrica(TNoA *a)
{
    if (a != NULL)
    {
        simetrica(a->esq);
        printf("%c\n", a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TNoA *a)
{
    if (a != NULL)
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c\n", a->info);
    }
}

int quantidade_nos(TNoA *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + quantidade_nos(raiz->esq) + quantidade_nos(raiz->dir);
    }
}
int altura(TNoA *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    int esq = 1 + altura(raiz->esq);
    int dir = 1 + altura(raiz->dir);
    if (esq > dir)
    {
        return esq;
    }
    else if (dir > esq)
    {
        return dir;
    }
    else if (dir == esq)
    {
        return esq;
    }
}
int binaria_cheia(int alt, int qt)
{
    int x = 0, i;
    for (i = 0; i < alt; i++)
    {
        x = x + pow(2, i);
    }
    if (x == qt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

TNoA *espelho(TNoA *a)
{

    if (a != NULL)
    {
        TNoA *raizEspelho = (TNoA *)malloc(sizeof(TNoA));
        raizEspelho->info = a->info;
        raizEspelho->esq = espelho(a->dir);
        raizEspelho->dir = espelho(a->esq);
        return raizEspelho;
    }
    return NULL;
}

void main()
{
    TNoA *raiz;
    raiz = criaNo("A");
    raiz->esq = criaNo("B");
    raiz->dir = criaNo("C");
    raiz->dir->esq = criaNo("D");
    raiz->dir->dir = criaNo("E");
    imprime(raiz, 0);
}