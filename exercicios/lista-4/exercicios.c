#include <stdio.h>
#include <stdlib.h>

typedef struct viz
{
    int no_viz;
    struct viz *prox_viz;
} TV;

typedef struct grafo
{
    int no;
    struct grafo *prox;
    TV *prim;
} TG;

TG *TG_inicializa()
{
    return NULL;
}

void TG_imprime(TG *g)
{
    while (g)
    {
        printf("Vizinhos do No %d:\n", g->no);
        TV *v = g->prim;
        while (v)
        {
            printf("%d ", v->no_viz);
            v = v->prox_viz;
        }
        printf("\n");
        g = g->prox;
    }
}

void TG_imp_rec(TG *g)
{
    if (g)
    {
        printf("%d:\n", g->no);
        TV *v = g->prim;
        while (v)
        {
            printf("%d ", v->no_viz);
            v = v->prox_viz;
        }
        TG_imp_rec(g->prox);
    }
}

void TG_libera_viz(TV *v)
{
    while (v)
    {
        TV *temp = v;
        v = v->prox_viz;
        free(temp);
    }
}

void TG_libera_viz_rec(TV *v)
{
    if (!v)
        return;
    TG_libera_viz_rec(v->prox_viz);
    free(v);
}

void TG_libera(TG *g)
{
    while (g)
    {
        TG_libera_viz(g->prim);
        TG *temp = g;
        g = g->prox;
        free(temp);
    }
}

void TG_libera_rec(TG *g)
{
    if (g)
    {
        TG_libera_viz(g->prim);
        TG_libera_rec(g->prox);
        free(g);
    }
}

TG *TG_busca_no(TG *g, int x)
{
    if ((!g) || (g->no == x))
        return g;
    return (TG_busca_no(g->prox, x));
}

TV *TG_busca_aresta(TG *g, int no1, int no2)
{
    TG *p1 = TG_busca_no(g, no1), *p2 = TG_busca_no(g, no2);
    if ((!p1) || (!p2))
        return NULL;
    TV *resp = p1->prim;
    while ((resp) && (resp->no_viz != no2))
        resp = resp->prox_viz;
    return resp;
}

TG *TG_ins_no(TG *g, int x)
{
    TG *p = TG_busca_no(g, x);
    if (!p)
    {
        p = (TG *)malloc(sizeof(TG));
        p->no = x;
        p->prox = g;
        p->prim = NULL;
        g = p;
    }
    return g;
}

void TG_ins_um_sentido(TG *g, int no1, int no2)
{
    TG *p = TG_busca_no(g, no1);
    if (!p)
        return;
    TV *nova = (TV *)malloc(sizeof(TV));
    nova->no_viz = no2;
    nova->prox_viz = p->prim;
    p->prim = nova;
}

void TG_ins_aresta(TG *g, int no1, int no2)
{
    TV *v = TG_busca_aresta(g, no1, no2);
    if (v)
        return;
    TG_ins_um_sentido(g, no1, no2);
    TG_ins_um_sentido(g, no2, no1);
}

void TG_retira_um_sentido(TG *g, int no1, int no2)
{
    TG *p = TG_busca_no(g, no1);
    if (!p)
        return;
    TV *ant = NULL, *atual = p->prim;
    while ((atual) && (atual->no_viz != no2))
    {
        ant = atual;
        atual = atual->prox_viz;
    }
    if (!ant)
        p->prim = atual->prox_viz;
    else
        ant->prox_viz = atual->prox_viz;
    free(atual);
}

void TG_retira_aresta(TG *g, int no1, int no2)
{
    TV *v = TG_busca_aresta(g, no1, no2);
    if (!v)
        return;
    TG_retira_um_sentido(g, no1, no2);
    TG_retira_um_sentido(g, no2, no1);
}

TG *TG_retira_no(TG *g, int no)
{
    TG *p = g, *ant = NULL;
    while ((p) && (p->no != no))
    {
        ant = p;
        p = p->prox;
    }
    if (!p)
        return g;
    while (p->prim)
        TG_retira_aresta(g, no, p->prim->no_viz);
    if (!ant)
        g = g->prox;
    else
        ant->prox = p->prox;
    free(p);
    return g;
}

// Q1
int nn(TG *g)
{
    if (!g)
        return 0;
    if (g->prox)
        return 1 + nn(g->prox);
    return 1;
}

// Q2
int nv(TG *g)
{
    if (!g)
        return 0;
    int qtdV = 0;
    while (g)
    {
        if (g->prim)
        {
            TV *aux = g->prim;
            while (aux)
            {
                qtdV++;
                aux = aux->prox_viz;
            }
        }
        g = g->prox;
    }

    return qtdV;
}

// Q3
int testek(TG *g, int k)
{
    if (!g)
        return 0;
    while (g)
    {
        int qtd = 0;
        if (g->prim)
        {
            TV *v = g->prim;
            while (v)
            {
                qtd++;
                v = v->prox_viz;
            }
        }
        if (qtd != k)
            return 0;
        g = g->prox;
    }
    return 1;
}

// Q4
int iguais(TG *g1, TG *g2)
{
    if (!g1 && !g2)
        return 1;
    if (g1->no == g2->no)
    {
        TV *v1 = g1->prim, *v2 = g2->prim;
        while (v1 || v2)
        {
            if (!v1 || !v2)
                return 0;
            if (v1->no_viz == v2->no_viz)
            {
                v1 = v1->prox_viz;
                v2 = v2->prox_viz;
            }
            else
                return 0;
        }
        if (!g1->prox && !g2->prox)
            return 1;
        else
        {
            g1 = g1->prox;
            g2 = g2->prox;
        }
    }
    else
        return 0;

    return 1;
}

//Q5
int nao_tem_mesma_cor(TG *g) {
    
}
