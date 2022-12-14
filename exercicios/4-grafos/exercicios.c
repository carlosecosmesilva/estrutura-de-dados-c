#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho
{
    int cor;
    int noVizinho;
    TVizinho *proxVizinho;
} TVizinho;

typedef struct grafo
{
    int cor;
    int noGrafo;
    TGrafo *proxGrafo;
    TVizinho *primViz;
} TGrafo;

TGrafo *inicializarGrafo()
{
    return NULL;
}

void imprimir(TGrafo *g)
{
    if (g)
    {
        printf("%d:\n", g->noGrafo);
        TVizinho *v = g->primViz;
        while (v)
        {
            printf("%d ", v->noVizinho);
            v = v->proxVizinho;
        }
        imprimir(g->proxGrafo);
    }
}

void liberarVizinho(TVizinho *v)
{
    if (!v)
        return;
    liberarVizinho(v->proxVizinho);
    free(v);
}

void liberarGrafo(TGrafo *g)
{
    if (g)
        liberarVizinho(g->primViz);
    liberarGrafo(g->proxGrafo);
    free(g);
}

TGrafo *buscarNo(TGrafo *g, int x)
{
    if ((!g) || (g->noGrafo == x))
    {
        return g;
    }
    return (buscarNo(g->proxGrafo, x));
}

TGrafo *buscarAresta(TGrafo *g, int primNo, int segNo)
{
    TGrafo *p1 = buscarNo(g, primNo);
    TGrafo *p2 = buscarNo(g, segNo);

    if ((!p1) || (!p2))
    {
        return NULL;
    }

    TVizinho *aresta = p1->primViz;

    while ((aresta) && (aresta->noVizinho != segNo))
    {
        aresta = aresta->proxVizinho;
    }

    return aresta;
}

TGrafo *inserirNo(TGrafo *g, int x)
{
    TGrafo *p = buscarNo(g, x);
    if (!p)
    {
        p = (TGrafo *)malloc(sizeof(TGrafo));
        p->noGrafo = x;
        p->proxGrafo = g;
        p->primViz = NULL;
        g = p;
    }
    return g;
}

void inserirUmSentido(TGrafo *g, int primNo, int segNo)
{
    TGrafo *p = buscarNo(g, primNo);
    if (!p)
    {
        return;
    }
    TVizinho *novo = (TVizinho *)malloc(sizeof(TVizinho));
    novo->noVizinho = segNo;
    novo->proxVizinho = p->primViz;
    p->primViz = novo;
}

void inserirAresta(TGrafo *g, int primNo, int segNo)
{
    TVizinho *v = buscarAresta(g, primNo, segNo);
    if (v)
    {
        return;
    }
    inserirUmSentido(g, primNo, segNo);
    inserirUmSentido(g, segNo, primNo);
}

void retirarUmSentido(TGrafo *g, int primNo, int segNo)
{
    TGrafo *p = buscarNo(g, primNo);
    if (!p)
    {
        return;
    }
    TVizinho *ant = NULL;
    TVizinho *atual = p->primViz;
    while ((atual) && (atual->noVizinho != segNo))
    {
        ant = atual;
        atual = atual->proxVizinho;
    }
    if (!ant)
    {
        p->primViz = atual->proxVizinho;
    }
    else
    {
        ant->proxVizinho = atual->proxVizinho;
    }
    free(atual);
}

void retirarAresta(TGrafo *g, int primNo, int segNo)
{
    TVizinho *v = buscarAresta(g, primNo, segNo);
    if (!v)
    {
        return;
    }
    retirarUmSentido(g, primNo, segNo);
    retirarUmSentido(g, primNo, segNo);
}

TGrafo *retiraNo(TGrafo *g, int no)
{
    TGrafo *p = g;
    TGrafo *ant = NULL;

    while ((p) && (p->noGrafo != no))
    {
        ant = p;
        p = p->proxGrafo;
    }
    if (!p)
    {
        return g;
    }
    while (p->primViz)
    {
        retirarAresta(g, no, p->primViz->noVizinho);
    }
    if (!ant)
    {
        g = g->proxGrafo;
    }
    else
    {
        ant->proxGrafo = p->proxGrafo;
    }
    free(p);
    return g;
}

int verificarQtdDeNos(TGrafo *g)
{
    if (!g)
    {
        return 0;
    }
    if (g->proxGrafo)
    {
        return 1 + verificarQtdDeNos(g->proxGrafo);
    }
    return 1;
}

int verificarQtdDeVertices(TGrafo *g)
{
    if (!g)
    {
        return 0;
    }
    int qtdVertices = 0;
    while (g)
    {
        if (g->primViz)
        {
            TVizinho *aux = g->primViz;
            while (aux)
            {
                qtdVertices++;
                aux = aux->proxVizinho;
            }
        }
        g = g->proxGrafo;
    }
    return qtdVertices;
}

int verificarGrauDeNos(TGrafo *g, int x)
{
    if (!g)
    {
        return 0;
    }
    while (g)
    {
        int qtd = 0;
        if (g->primViz)
        {
            TVizinho *v = g->primViz;
            while (v)
            {
                qtd++;
                v = v->proxVizinho;
            }
        }
        if (qtd != x)
        {
            return 0;
        }
        g = g->proxGrafo;
    }
    return 1;
}

int verificarGrafosIguais(TGrafo *primGraf, TGrafo *segGrafo)
{
    if (!primGraf && !segGrafo)
    {
        return 1;
    }
    else if (primGraf->noGrafo == segGrafo->noGrafo)
    {
        TVizinho *primViz = primGraf->primViz;
        TVizinho *segViz = segGrafo->primViz;
        while (primViz || segViz)
        {
            if (!primViz || segViz)
            {
                return 0;
            }
            else if (primViz->noVizinho == segViz->noVizinho)
            {
                primViz = primViz->proxVizinho;
                segViz = segViz->proxVizinho;
            }
            else
            {
                return 0;
            }
        }
        if (!primGraf->proxGrafo && !segGrafo->proxGrafo)
        {
            return 1;
        }
        else
        {
            primGraf = primGraf->proxGrafo;
            segGrafo = segGrafo->proxGrafo;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

int verificarSeCorIgual(TGrafo *g)
{
    int resultado = 1;
    TGrafo *aux = g;
    while (aux != NULL)
    {
        TVizinho *v = aux->primViz;
        while (v != NULL)
        {
            if (v->cor == aux->cor)
            {
                resultado = 0;
            }
            v->proxVizinho;
        }
        aux = aux->proxGrafo;
    }

    return resultado;
}

int main()
{
    TGrafo *grafoTeste = inicializarGrafo();
    grafoTeste = inserirUmSentido(grafoTeste, 10, 5);
    grafoTeste = inserirUmSentido(grafoTeste, 12, 5);
    grafoTeste = inserirUmSentido(grafoTeste, 17, 7);
    grafoTeste = inserirUmSentido(grafoTeste, 1, 8);
    inserirAresta(grafoTeste, 10, 12, 5, 5);

    imprimir(grafoTeste);
    int teste = verificarGrafosIguais(grafoTeste);

    printf("%d \n", teste);
}
