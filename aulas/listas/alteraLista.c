#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

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
    {
        printf("%d\n", p->info);
    }
    printf("-------------------------------\n");
}

TLista *altera(TLista *li, int vantigo, int vnovo)
{
    TLista *p;
    int cont = 0;
    for (p = li; p != NULL; p = p->prox)
    {
        if (p->info == vantigo)
        {
            p->info = vnovo;
            cont = 1; // se valor antigo for achado, cont = 1, caso contrario, usa-se para dizer que nao achou
        }
    }
    if (cont == 0)
    {
        printf("Valor a substituir nao encontrado.\n");
    }
    return li;
}

int main()
{
    TLista *li = cria_lista();

    li = insere_inicio(li, 10);
    li = insere_inicio(li, 30);
    li = insere_inicio(li, 20);
    li = insere_inicio(li, 40);

    imprime_lista(li);

    li = altera(li, 70, 50);

    imprime_lista(li);

    return 0;
}