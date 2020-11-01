#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct agendaNomes
{
    char nome[100];
    struct agendaNomes *prox;
};

typedef struct agendaNomes agN;
agN *criaLista();
void adicionarNome(agN *inicio);
void removerNome(agN *inicio);
void listarNome(agN *inicio);

int main()
{
    agN *inicio, *pos;  /*Dia 24/10 compilei o agendaNomes com o -Wall no terminal e ele detectou erro nessa linha. O erro era o *pos que estava sem uso*/
    inicio = criaLista();
    int op;

    do
    {

        printf("\n---------------- MENU DA AGENDA DE NOMES -------------------\n");
        printf("\t1 - Adicionar nome\n\t2 - Remover nome\n\t3 - Listar nome\n\t4 - Sair\n");
        printf("\tDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            //adicionar nomes
            adicionarNome(inicio);
            break;

        case 2:
            //remover nomes
            removerNome(inicio);
            break;

        case 3:
            //listar nomes
            listarNome(inicio);
            break;

        case 4:
            //sair da agenda
            printf("\nSaindo!");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }
    } while (op != 4);

    return 0;
}

agN *criaLista()
{
    agN *start;

    start = (agN *)malloc(sizeof(agN));
    start->prox = NULL;
    return start;
}

void adicionarNome(agN *inicio)
{
    agN *nvNome;
    nvNome = (agN *)malloc(sizeof(agN));

    printf("\n\t----- Adicionando Nomes -----");
    printf("\n\tDigite um nome: ");
    scanf("%s", nvNome->nome);
    nvNome->prox = inicio->prox;
    inicio->prox = nvNome;
}

void removerNome(agN *inicio)
{
    agN *p, *q;
    char nome[100];

    printf("\n\t----- Removendo Nomes -----");
    printf("\n\tDigite um nome para remover: ");
    scanf("%s", nome);

    p = inicio;
    q = inicio->prox;
    while ((q != NULL) && (strcmp(q->nome, nome) != 0))
    {
        p = q;
        q = q->prox;
    }
    if (q != NULL)
    {
        p->prox = q->prox;
        free(q);
        printf("\tNome removido com sucesso!\n");
    }
    else
    {
        printf("\tNao foi possivel remover.\n");
    }
}

void listarNome(agN *inicio)
{
    agN *listar;

    printf("\n\t----- Lista de Nomes -----");
    for (listar = inicio->prox; listar != NULL; listar = listar->prox)
    {
        printf("\n\tNome: %s\n", listar->nome);
    }
}
