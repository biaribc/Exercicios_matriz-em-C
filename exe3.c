#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro res;
struct cadastro
{
    char nome[100], endereco[100], comida[50];
    float preco;
} restaurante[100];
void incluir(res *restaurante, int indice)
{
    puts("Nome:");
    scanf("%s", &restaurante[indice].nome);
    puts("Endereco:");
    scanf("%s", &restaurante[indice].endereco);
    puts("Tipo de Comida:");
    scanf("%s", &restaurante[indice].comida);
    puts("Preco Medio:");
    scanf("%f", &restaurante[indice].preco);
}
void listar(res *restaurante, int indice)
{
    puts("Nome:");
    printf("%s\n", restaurante[indice].nome);
    puts("Endereco:");
    printf("%s\n", restaurante[indice].endereco);
    puts("Tipo de Comida:");
    printf("%s\n", restaurante[indice].comida);
    puts("Preco Medio:");
    printf("R$ %.2f\n", restaurante[indice].preco);
}
int main(void)
{
    int i, opcao, indice = 0;
    do
    {
        puts("\tO que voce deseja executar?");
        puts("1 - Incluir Restaurante");
        puts("2 - Listar Restaurantes");
        puts("0 - SAIR");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            incluir(restaurante, indice);
            indice++;
            break;
        case 2:
            for (i = 0; i < indice; i++)
            {
                listar(restaurante, i);
            }
            break;
        }
    } while (opcao != 0);
}
