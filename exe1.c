#include <stdio.h>
#include <stdlib.h>
typedef struct dado item;

struct dado
{
    int codigo;
    char nome[50];
    float preco;
    int diabaixa[4][6];
};
int main()
{
    int baixa, i, n, x, soma, maior = 0, maisvendido;
    item produto[1000];

    do
    {
        puts("Para encerrar o programa digite 0 para o codigo");
        puts("Codigo:");
        scanf("%i", &produto[i].codigo);
        if (produto[i].codigo == 0)
            break;
        puts("Nome:");
        scanf("%s", &produto[i].nome);
        puts("Preco:");
        scanf("%f", &produto[i].preco);
        for (x = 0; x < 4; x++)
        {
            printf("Semana %i\n", x + 1);
            for (n = 0; n < 6; n++)
            {
                printf("\tQuantidade de baixas do dia %i:\n ", n + 1);
                scanf("%i", &produto[i].diabaixa[x][n]);
            }
        }
        i++;
    } while (produto[i].codigo != 0);
    i = 0;
    while (produto[i].codigo != NULL)
    {
        for (x = 1; x <= 4; x++)
        {
            soma = 0;
            for (n = 1; n <= 6; n++)
            {
                soma = soma + produto[i].diabaixa[x][n];
            }
            if (soma > maior)
            {
                maior = soma;
                maisvendido = i;
            }
        }
        i++;
    }
    printf("\nO produto mais vendido foi %i com %i baixas", produto[maisvendido].nome, maior);
    return 0;
}
