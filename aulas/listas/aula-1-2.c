#include <stdio.h>
#include <stdlib.h>
#define TAM 5

float pegarValores(float *v)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("Digite a %d nota: \n", i + 1);
        scanf("%f", &v[i]);
    }

    return v[TAM];
}

float calcularMedia(int n, float *v)
{
    int i;
    float media = 0.0;

    for (i = 0; i < TAM; i++)
    {
        media += v[i];
    }

    return media / n;
}

int main()
{   
    int i, n;
    float *v, med;

    v = (float*) malloc(n * sizeof(float));

    if (v == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1); 
    }

    pegarValores(v);
    med = calcularMedia(5, v);
    
    if (med >= 6)
    {
        printf("Media = %.2f ", med, " APROVADO");
    }
    else
    {
        printf("Media = %.2f ", med, " REPROVADO");
    }

    free(v);
    return 0;
}
