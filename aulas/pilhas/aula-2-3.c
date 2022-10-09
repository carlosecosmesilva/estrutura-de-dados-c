#include "E:\GitHub\estrutura-de-dados-c\aulas\pilhas\Lista.c"

// Define a pilha
typedef struct pilha
{
    TLista *topo;
    int elemento;

} TPilha;

TPilha *criarPilha()
{
    // aloca espaço para criar uma pilha
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    if (pilha != NULL)
    {
        // Seta o valor dos nós
        pilha->topo = NULL;
        pilha->elemento = 0;
    }
    else
    {
        printf("\n Memória Cheia!\n");
    }
}

// Retorna se a Pilha está vazia ou não
int verificarSePilhaVazia(TPilha *pilha)
{
    if (pilha->elemento > 0 && pilha->topo != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Adiciona o nó ao topo da pilha
void push(TPilha *pilha, int i)
{

    // Cria um novo nó
    TLista *no = (TLista *)malloc(sizeof(TLista));

    if (no == NULL)
    {
        printf("\n Estouro de memoria ao criar novo no da pilha \n");
    }
    else
    {
        no->info = i;
        no->prox = pilha->topo;
    }

    // Adiciona informações a pilha
    pilha->topo = no;
    pilha->elemento++;
}
// Retorna o topo de informações da pilha
int peek(TPilha *pilha)
{
    return pilha->topo->info;
}
// Remove o topo da pilha
void pop(TPilha *pilha)
{
    if (verificarSePilhaVazia(pilha) == 0)
    {
        TLista *temp = pilha->topo;
        // Alterar informações do topo da pilha
        pilha->topo = temp->prox;
        // Remover topo anterior
        free(temp);
        temp = NULL;
        pilha->elemento--;
    }
}
// Determina se as pilha são iguais ou não
int compararPilhas(TPilha *p1, TPilha *p2)
{

    if (p1->elemento != p2->elemento)
    {
        // Retorna 0 quando não são iguais
        return 0;
    }

    // This is backup pilha
    TPilha *b1 = criarPilha();
    TPilha *b2 = criarPilha();

    int status = 1;
    // Quando ambas as pilhas possuirem informação e seu status for ativo irá executar o laço abaixo
    while (verificarSePilhaVazia(p1) == 0 && verificarSePilhaVazia(p2) == 0 && status == 1)
    {
        if (peek(p1) != peek(p2))
        {
            // Retorna status 0 se as informações não forem iguais
            status = 0;
        }
        else
        {
            // Efetua backup das informações atuais
            push(b1, peek(p1));
            push(b2, peek(p2));
            // Remove o topo da pilha
            pop(p1);
            pop(p2);
        }
    }
    // Coloca todas as informações do pop na pilha real
    while (verificarSePilhaVazia(b1) == 0)
    {
        push(p1, peek(b1));
        push(p2, peek(b2));
        pop(b1);
        pop(b2);
    }

    return status;
}
// Print pilha info
void printInfo(TPilha *s)
{
    if (verificarSePilhaVazia(s) == 1)
    {
        return;
    }
    int data = peek(s);
    printf("  %d", data);
    pop(s);
    printInfo(s);
    push(s, data);
}
// Lidar com solicitação para imprimir informações da pilha
void printPilhas(TPilha *p1, TPilha *p2)
{
    printf("\n Pilha 1 \n");
    printInfo(p1);
    printf("\n Pilha 2 \n");
    printInfo(p2);
}
int main()
{
    // Cria duas pilhas vazias
    TPilha *p1 = criarPilha();
    TPilha *p2 = criarPilha();

    // Primeira pilha
    push(p1, 1);
    push(p1, 2);
    push(p1, 3);

    // Segunda pilha
    push(p2, 1);
    push(p2, 2);
    push(p2, 3);

    printPilhas(p1, p2);

    if (compararPilhas(p1, p2) == 1)
    {

        printf("\n As Pilhas sao iguais\n");
    }
    else
    {
        printf("\n As Pilhas nao sao iguais\n");
    }

    push(p1, 4);
    push(p2, 5);

    printPilhas(p1, p2);
    if (compararPilhas(p1, p2) == 1)
    {
        printf("\n As Pilhas sao iguais \n");
    }
    else
    {
        printf("\n As Pilhas nao sao iguais\n");
    }

    return 0;
}