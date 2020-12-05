#include <stdio.h>
#include <stdlib.h>

int *removerRepeticoes(int *vetor, int n);

int main()
{

    int n, *vetor;

    printf("\nInforme um valor pra N: ");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));

    printf("Informe os %d elementos do vetor: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("Vetor Normal: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    removerRepeticoes(vetor, n);
    free(vetor);
    return 0;
}

int *removerRepeticoes(int *vetor, int n)
{
    int semRepeticao = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[i] == vetor[j])
            {
                for (int k = j; k < n; k++)
                {
                    vetor[k] = vetor[k + 1];
                }
                n--;
                semRepeticao++;
            }
        }
    }

    if (semRepeticao == 0)
    {
        printf("\nNao ha repeticoes nesse vetor.\n");
    }
    else
    {
        printf("\nVetor sem numeros repetidos: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vetor[i]);
        }
    }
    return vetor;
}