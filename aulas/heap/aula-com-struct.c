#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int max;
    int pos;
    int *prioridade;
} THeap;

THeap *criarHeap(int max)
{
    THeap *newHeap = (THeap *)malloc(sizeof(THeap));
    newHeap->max = max;
    newHeap->pos = 0;
    newHeap->prioridade = (int *)malloc(max * sizeof(int));
    return newHeap;
}

void inserirHeap(THeap *heap, int prioridade)
{
    if (heap->pos < heap->max)
    {
        heap->prioridade[heap->pos] = prioridade;
        corrigir(heap, heap->pos);
        heap->pos++;
    }
    else
    {
        printf("Heap Cheio!");
    }
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
        if (heap->prioridade[pai] < heap->prioridade[pos])
        {
            trocar(pos, pai, heap->prioridade);
        }
        else
        {
            break;
        }
        pos = pai;
    }
}

int removerHeap(THeap *heap)
{
    if (heap->pos > 0)
    {
        int topo = heap->prioridade[0];
        heap->prioridade[0] = heap->prioridade[heap->pos - 1];
        heap->pos--;
        corrigirAbaixo(heap->prioridade, 0, heap->pos);
        return topo;
    }
    else
    {
        printf("Heap VAZIO!");
        return -1;
    }
}
void mostrarInformacoes(THeap *heap, int i)
{
    if (heap == NULL || i < 0)
    {
        printf("O no %d nao existe!\n", i);
        return;
    }

    printf("Indice %d\n", i);
    printf("Pai do no %d: %d\n", heap->prioridade[i], mostrarPai(heap, i));
    printf("Filho esquerdo %d: %d\n", heap->prioridade[i], mostrarFilhoEsquerdo(heap, i));
    printf("Filho direito %d: %d\n", heap->prioridade[i], mostrarFilhoDireito(heap, i));
}

int mostrarPai(THeap *heap, int i)
{
    if (heap == NULL || i < 0 || i > heap->max)
    {
        return -1;
    }

    return heap->prioridade[(i - 1) / 2];
}

int mostrarFilhoEsquerdo(THeap *heap, int i)
{
    if (heap == NULL || i < 0 || i > heap->max)
    {
        return -1;
    }

    return heap->prioridade[(2 * i + 1)];
}

int mostrarFilhoDireito(THeap *heap, int i)
{
    if (heap == NULL || i < 0 || i > heap->max)
    {
        return -1;
    }

    return heap->prioridade[(2 * i + 2)];
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
    percorrerVetor(heap->prioridade, heap->max);
    printf("\n");

    /* mostra informacoes sobre um determinado noh */
    int indice = 3;
    mostrarInformacoes(heap, indice);
    printf("\n");

    /* remove o elemento de maior prioridade da arvore */
    removerHeap(&heap);

    /* mostra o max-heap apos a remocao */
    printf("Max-Heap apos a remocao do elemento de maior prioridade:\n");
    percorrerVetor(heap->prioridade, heap->max);
    printf("\n");

    /* mostra o max-heap apos o algoritmo de ordenacao HeapSort */
    printf("Max-Heap apos o algoritmo de ordenacao HeapSort:\n");
    heapSort(&heap);
    percorrerVetor(heap->prioridade, heap->max);
    printf("\n");

    /* destroi o max-heap */
    destruirHeap(&heap);
    return 0;
}
