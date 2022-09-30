#include <stdio.h>

void trocar(int *px, int *py)
{
    int vTemp;
    vTemp = *px;
    *px = *py;
    *py = vTemp;
}

int main()
{
    int a = 5, b = 7;
    trocar(&a, &b); /* passando o endereço das variaveis para a função */
    printf("%d %d \n", a, b);
    return 0;
}
