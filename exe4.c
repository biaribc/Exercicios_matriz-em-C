#include <stdio.h>
#include <stdlib.h>

typedef struct dieta res;
struct dieta
{
    char nome[50];
    float peso, caloria;
} comida[100];
void incluir(res *comida, int indice)
{
    puts("Nome:");
    scanf("%s", &comida[indice].nome);
    puts("Peso em g:");
    scanf("%f", &comida[indice].peso);
    puts("Calorias:");
    scanf("%f", &comida[indice].caloria);
}
void listar(res *comida, int indice)
{
    puts("Nome:");
    printf("%s\n", comida[indice].nome);
    puts("Peso:");
    printf("%f\n", comida[indice].peso);
    puts("Calorias:");
    printf("%f\n", comida[indice].caloria);
}
int main(void)
{
    int i, opcao, indice = 0;
    do
    {
        puts("\tO que voce deseja executar?");
        puts("1 - Incluir Comida");
        puts("2 - Listar Comidas");
        puts("0 - SAIR");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            incluir(comida, indice);
            indice++;
            break;
        case 2:
            for (i = 0; i < indice; i++)
            {
                listar(comida, i);
            }
            break;
        }
    } while (opcao != 0);
}
