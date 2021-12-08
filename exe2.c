#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dado cad;
struct dado
{
    int matricula, serie, nasc, turma;
    char nome[50], sexo[20];
    float media;
    bool aprov;
} aluno[100];
void inserir(cad *aluno, int indice);
void imprime(cad *aluno, int indice);
void calcula(cad *aluno, int indice);
void calculasexo(cad *aluno, int indice);

int main()
{
    int i, indice = 0, opcao;
    do
    {
        puts("---------------MENU-----------------");
        puts("1-inserir");
        puts("2-imprimir");
        puts("3-Apresentar porccentagem aprovacao");
        puts("4- Apresentar porcentagem por genero");
        puts("5- Apresentar media de idades");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 1:
            inserir(aluno, indice);
            indice++;
            break;
        case 2:
            for (i = 0; i < indice; i++)
            {
                imprime(aluno, i);
            }
            break;
        case 3:
            calcula(aluno, i);
            break;
        case 4:
            calculasexo(aluno, i);
            break;
        }
    } while (opcao > 0);

    return 0;
}
void inserir(cad *aluno, int indice)
{
    puts("Matricula:");
    scanf("%i", &aluno[indice].matricula);
    puts("Nome:");
    scanf("%s", &aluno[indice].nome);
    puts("Ano de Nascimento:");
    scanf("%i", &aluno[indice].nasc);
    puts("Serie:");
    scanf("%i", &aluno[indice].serie);
    puts("Turma:");
    scanf("%i", &aluno[indice].turma);
    puts("Sexo:");
    scanf("%s", &aluno[indice].sexo);
    puts("Media:");
    scanf("%f", &aluno[indice].media);
    if (aluno[indice].media >= 7)
        aluno[indice].aprov = true;
    else
        aluno[indice].aprov = false;
}
void imprime(cad *aluno, int indice)
{
    printf("Matricula: %i\n", aluno[indice].matricula);
    printf("Nome: %s\n", aluno[indice].nome);
    printf("Turma: %i\n", aluno[indice].turma);
    printf("Serie: %i\n", aluno[indice].serie);
    printf("Media: %.2f\n", aluno[indice].media);
    printf("Ano de Nascimento: %i\n", aluno[indice].nasc);
    if (aluno[indice].aprov == true)
        printf("\nAPROVADO!\n");
    else
        printf("\nREPROVADO\n");
}
void calcula(cad *aluno, int indice)
{
    int i, k;
    float mediageral, x, n;
    for (i = 0; i <= 5; i++)
    {
        n = 0;
        x = 0;
        for (k = 0; k <= indice; k++)
        {
            if (aluno[k].turma == i)
            {
                if (aluno[k].aprov == true)
                    x++;
                n++;
            }
        }
        mediageral = (x / n) * 100;
        printf("A turma %i possui %.2f  de alunos aprovados\n", i, mediageral);
    }
}
void calculasexo(cad *aluno, int indice)
{
    int i, k;
    float mediageral, x, n, z;
    for (i = 0; i <= 5; i++)
    {
        n = 0;
        x = 0;
        for (k = 0; k <= indice; k++)
        {
            if (aluno[k].turma == i)
            {
                if (stricmp(aluno[k].sexo, "masculino") == 0)
                    x++;
                n++;
            }
        }
        x = n - x;
        mediageral = (x / n) * 100;
        printf("A turma %i possui %.2f /% de alunos do sexo masculino e %.2f do sexo feminino \n", i, mediageral, 100 - mediageral);
    }
}
void calculaidade(cad *aluno, int indice)
{
    int i, k;
    float mediageral, x, n;
    for (i = 0; i <= 5; i++)
    {
        n = 0;
        x = 0;
        for (k = 0; k <= indice; k++)
        {
            if (aluno[indice].turma == i)
            {
                x = x + (2021 - aluno[indice].nasc);
                n++;
            }
        }
        mediageral = x / n;
        printf("A turma %i possui %.2f como media de idade\n", i, mediageral);
    }
}
