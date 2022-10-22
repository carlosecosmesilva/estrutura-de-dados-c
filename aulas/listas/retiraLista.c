#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};
typedef struct lista TLista;

TLista *cria_lista(void)
{
    return NULL;
}

TLista *insere_inicio(TLista *li, int i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

void imprime_lista(TLista *li)
{
    TLista *p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
    printf("--------------------------------------------\n");
}

TLista *exclui(TLista *li, int elem)
{
    TLista *p;
    TLista *c;

    if (li->prox == NULL)
    {
        return NULL;
    }
    if (li->info == elem)
    {
        p = li; // cria auxiliar para poder liberar memoria e nao quebrar a lista
        li = p->prox;
        printf("Elemento encontrado: %d\n", elem);
        printf("--------------------------------------------\n");
    }
    else
    {
        for (p = li; p != NULL; p = p->prox)
        {
            if (p->info == elem)
            {
                c->prox = p->prox; // c usado para percorrer a lista sempre um elemento antes de p
                printf("Elemento encontrado: %d\n", elem);
                printf("--------------------------------------------\n");
                break;
            }
            c = p;
        }
    }
    free(p);
    return li;
}

int main()
{
    TLista *li = cria_lista();
    TLista *excluido;

    li = insere_inicio(li, 10);
    li = insere_inicio(li, 30);
    li = insere_inicio(li, 20);
    li = insere_inicio(li, 40);

    imprime_lista(li);

    li = exclui(li, 10);

    imprime_lista(li);

    return 0;
}