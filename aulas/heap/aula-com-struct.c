#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int max;
    int pos;
    int *h;
} THeap;

THeap *criarHeap(THeap **heap)
{
    THeap *newHeap = (THeap *)malloc(sizeof(THeap));
    if (newHeap == NULL)
    {
        *heap = NULL;
    }
    newHeap->h = NULL;
    newHeap->max = 0;

    *heap = newHeap;
}

int *inicializarVetor(int n)
{
    int *novoVetor, i;

    novoVetor = (int *)malloc(n * sizeof(int));
    if (novoVetor == NULL)
    {
        return NULL;
    }

    return novoVetor;
}

void inserirHeap(THeap **heap, int k)
{
    if (*heap == NULL)
    {
        criarHeap(heap);
    }
    else if ((*heap)->max == 0)
    {
        (*heap)->max = 1;
        (*heap)->h = inicializarVetor(1);
        (*heap)->h[0] = k;
    }
    else
    {
        (*heap)->max += 1;
        (*heap)->h = realocarVetor((*heap)->h, (*heap)->max);
        (*heap)->h[(*heap)->max - 1] = k;
        subir(heap, (*heap)->max - 1);
    }
}

void subir(THeap **heap, int i)
{
    if (i < 0 || i > (*heap)->max || *heap == NULL)
    {
        return;
    }

    int j = (i - 1) / 2;
    int x = (*heap)->h[i];

    while (i > 0 && (*heap)->h[j] < x)
    {
        (*heap)->h[i] = (*heap)->h[j];
        i = j;
        j = (j - 1) / 2;
    }
    (*heap)->h[i] = x;
}

void trocar(int a, int b, int *v)
{
    int f = v[a];
    v[a] = v[b];
    v[b] = f;
}

void corrigirAcima(THeap *heap, int pos)
{
    int pai;
    while (pos > 0)
    {
        pai = (pos - 1) / 2;
        if (heap->h[pai] < heap->h[pos])
        {
            trocar(pos, pai, heap->h);
        }
        else
        {
            break;
        }
        pos = pai;
    }
}

int removerHeap(THeap **heap)
{
    (*heap)->h[0] = (*heap)->h[(*heap)->max - 1];
    (*heap)->max -= 1;
    (*heap)->h = realocarVetor((*heap)->h, (*heap)->max);
    descer(heap, 0);
}
void mostrarInformacoes(THeap *heap, int i)
{
    if (heap == NULL || i < 0)
    {
        printf("O no %d nao existe!\n", i);
        return;
    }

    printf("Indice %d\n", i);
    printf("Pai do no %d: %d\n", heap->h[i], mostrarPai(heap, i));
    printf("Filho esquerdo %d: %d\n", heap->h[i], mostrarFilhoEsquerdo(heap, i));
    printf("Filho direito %d: %d\n", heap->h[i], mostrarFilhoDireito(heap, i));
}

int mostrarPai(THeap *heap, int i)
{
    if (heap == NULL || i < 0 || i > heap->max)
    {
        return -1;
    }

    return heap->h[(i - 1) / 2];
}

int mostrarFilhoEsquerdo(THeap *heap, int i)
{
    if (heap == NULL || i < 0 || i > heap->max)
    {
        return -1;
    }

    return heap->h[(2 * i + 1)];
}

int mostrarFilhoDireito(THeap *heap, int i)
{
    if (heap == NULL || i < 0 || i > heap->max)
    {
        return -1;
    }

    return heap->h[(2 * i + 2)];
}

void corrigirAbaixo(int *prios, int atual, int tam)
{
    int pai = atual;
    int filhoEsq, filhoDir, filho;
    while (2 * pai + 1 < tam)
    {
        filhoEsq = 2 * pai + 1;
        filhoDir = 2 * pai + 2;
        if (filhoDir >= tam)
        {
            filhoDir = filhoEsq;
        }
        if (prios[filhoEsq] > prios[filhoDir])
        {
            filho = filhoEsq;
        }
        else
        {
            filho = filhoDir;
        }
        if (prios[pai] < prios[filho])
        {
            trocar(pai, filho, prios);
        }
        else
        {
            break;
        }
        pai = filho;
    }
}

void destruirHeap(THeap **heap)
{
    if (*heap != NULL)
    {
        free(*heap);
        *heap = NULL;
    }
}

int *realocarVetor(int *v, int n)
{
    if (v == NULL || n < 0)
    {
        return v;
    }

    int *tmp;
    tmp = (int *)realloc(v, n * sizeof(int));
    if (tmp == NULL)
    {
        return v;
    }

    return tmp;
}

void percorrerVetor(int *v, int n)
{
    if (v == NULL || n < 0)
    {
        return;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(v + 1));
    }
    printf("\n");
}

void descer(THeap **heap, int i)
{
    if (i < 0 || i > (*heap)->max || *heap == NULL)
    {
        return;
    }

    int k = 2 * i + 1;
    int x = (*heap)->h[i];

    while (k < (*heap)->max)
    {
        if ((k < ((*heap)->max - 1)) && ((*heap)->h[k] < (*heap)->h[k + 1]))
        {
            k++;
        }
        if (x < (*heap)->h[k])
        {
            (*heap)->h[i] = (*heap)->h[k];
            i = k;
            k = 2 * k + 1;
        }
        else
        {
            break;
        }
    }
    (*heap)->h[i] = x;
}

void heapSort(THeap **heap)
{
    int i, n = (*heap)->max, tmp;

    for (i = (n - 2) / 2; i >= 0; i--)
    {
        tmp = (*heap)->h[0];
        (*heap)->h[0] = (*heap)->h[i] = tmp;
        (*heap)->h[i] = tmp;
        (*heap)->max -= 1;
        descerHeap(heap, 0);
    }
    (*heap)->max = n;
}

int main()
{
    THeap *heap = NULL;

    /* insere valores no max-heap */
    criarHeap(&heap);
    inserirHeap(&heap, 100); // 1
    inserirHeap(&heap, 19);  // 4
    inserirHeap(&heap, 36);  // 2
    inserirHeap(&heap, 17);  // 3
    inserirHeap(&heap, 3);   // 9
    inserirHeap(&heap, 25);  // 5
    inserirHeap(&heap, 1);   // 6
    inserirHeap(&heap, 2);   // 7
    inserirHeap(&heap, 7);   // 8
    inserirHeap(&heap, 101); // 0 <- raiz

    /* mostra o max-heap */
    printf("Max-Heap antes da remocao:\n");
    percorrerVetor(heap->h, heap->max);
    printf("\n");

    /* mostra informacoes sobre um determinado noh */
    int indice = 3;
    mostrarInformacoes(heap, indice);
    printf("\n");

    /* remove o elemento de maior prioridade da arvore */
    removerHeap(&heap);

    /* mostra o max-heap apos a remocao */
    printf("Max-Heap apos a remocao do elemento de maior prioridade:\n");
    percorrerVetor(heap->h, heap->max);
    printf("\n");

    /* mostra o max-heap apos o algoritmo de ordenacao HeapSort */
    printf("Max-Heap apos o algoritmo de ordenacao HeapSort:\n");
    heapSort(&heap);
    percorrerVetor(heap->h, heap->max);
    printf("\n");

    /* destroi o max-heap */
    destruirHeap(&heap);
    return 0;
}
