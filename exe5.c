#include <stdio.h>
#include <stdlib.h>
typedef struct placa placa;
struct placa
{
    char letplacas[3];
    int numplacas[3];
};
typedef struct carros dado;
struct carros
{
    int chassi, ano;
    placa placa;
    char proprietario[50], modelo[50], combustivel[50], cor[20];

} carro[5000];

void list1(dado *carro, int indice)
{
    if (carro[indice].ano == 2010 && stricmp(carro[indice].combustivel, "diesel") == 0)
    {
        puts("Proprietario:");
        printf("%s\n", carro[indice].proprietario);
    }
}
void list2(dado *carro, int indice)
{
    if (carro[indice].placa.letplacas[0] == 'J' && (carro[indice].placa.numplacas[3] == 2 || carro[indice].placa.numplacas[3] == 0 || carro[indice].placa.numplacas[3] == 4 || carro[indice].placa.numplacas[3] == 7))
    {
        puts("Modelo:");
        printf("%s\n", carro[indice].modelo);
        puts("Ano:");
        printf("%i\n", carro[indice].ano);
    }
}
void list3(dado *carro, int indice)
{
    if ((carro[indice].placa.letplacas[1] == 'A' || carro[indice].placa.letplacas[1] == 'E' || carro[indice].placa.letplacas[1] == 'I' || carro[indice].placa.letplacas[1] == 'O' || carro[indice].placa.letplacas[1] == 'U') && (((carro[indice].placa.numplacas[0] + carro[indice].placa.numplacas[1] + carro[indice].placa.numplacas[2] + carro[indice].placa.numplacas[3]) % 2) == 0))
    {
        puts("Modelo:");
        printf("%s\n", carro[indice].modelo);
        puts("Ano:");
        printf("%i\n", carro[indice].ano);
    }
}
void troca(dado *carro, int i)
{
    int chassi, indice;
    char proprietario[50];
    puts("Insira o numero do chassi:");
    scanf("%i", &chassi);
    for (indice = 0; indice < i; indice++)
    {
        if ((carro[indice].chassi == chassi) && ((carro[indice].placa.numplacas[0] != 0) && (carro[indice].placa.numplacas[1] != 0) && (carro[indice].placa.numplacas[2] != 0) && (carro[indice].placa.numplacas[3] != 0)))
        {
            puts("Novo nome de proprietario:");
            scanf("%s", carro[indice].proprietario);
        }
    }
}
int main(void)
{
    int i, opcao, indice = 0;
    do
    {
        puts("\tO que voce deseja executar?");
        puts("1 - Listar proprietarios de veiculos 2010 movidos a diesel");
        puts("2 - Listar veiculos com placa J terminadas em 0,2,4 ou 7");
        puts("3 - Listar cor dos veiculos com segunda letra vogal");
        puts("4 - Trocar proprietario");
        puts("0 - SAIR");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            for (i = 0; i < indice; i++)
            {
                list1(carro, i);
            }
            break;
        case 2:
            for (i = 0; i < indice; i++)
            {
                list2(carro, i);
            }
            break;
        case 3:
            for (i = 0; i < indice; i++)
            {
                list3(carro, i);
            }
            break;
        case 4:
            troca(carro,indice);
            break;
        }
    } while (opcao != 0);
    return 0;
}
