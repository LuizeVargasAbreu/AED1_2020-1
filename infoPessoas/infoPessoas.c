#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
    float altura;
} Pessoa;

int main()
{

    Pessoa *p;
    int op, qtdPessoas = 0;
    
    p = (Pessoa *)malloc(sizeof(Pessoa));
        if (!p)
        {
            printf("Erro! Falta de memoria.");
            return -1;
        }

    do
    {

        printf("\n\t----- Armazenando de Informacoes de Pessoas -----");
        printf("\n\t1 - Adicionar dados\n\t0 - Sair\n");
        printf("\tDigite a opcao desejada: ");
        scanf("%d", &op);

        

        switch (op)
        {
        case 1:

            p = (Pessoa *) realloc(p, (qtdPessoas + 1) * sizeof(Pessoa));
            printf("\n\tInforme um nome: ");
            scanf("%s", p[qtdPessoas].nome);
            printf("\tInforme uma idade: ");
            scanf("%d", &p[qtdPessoas].idade);
            printf("\tInforme uma altura: ");
            scanf("%f", &p[qtdPessoas].altura);
            qtdPessoas++;
            break;

        case 0:

            if (qtdPessoas == 0)
            {
                printf("\n\tNenhum dado foi informado!\n");
            }
            else
            {
                printf("\n\t----- Imprimindo todos os Dados Informados -----\n");
                for (int i = 0; i < qtdPessoas; i++)
                {
                    printf("\n\tNome: %s ", p[i].nome);
                    printf("\tIdade: %d ", p[i].idade);
                    printf("\tAltura: %.2f ", p[i].altura);
                }
                free(p);
            }
            break;

        default:
            printf("\n\tOpcao invalida! Tente novamente.\n");
            break;
        }
    } while (op != 0);
    return 0;
}