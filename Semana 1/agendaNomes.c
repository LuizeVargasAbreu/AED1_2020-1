#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct agendaNomes
{
    char nome[100];
    struct agendaNomes *prox;               // endereço do próximo conteúdo
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

agN *criaLista()  //criando uma lista vazia com cabeça
{
    agN *start;

    start = (agN *)malloc(sizeof(agN));
    start->prox = NULL;
    return start;
}

void adicionarNome(agN *inicio)  //inserindo uma nova celula na lista
{
    agN *nvNome;
    nvNome = (agN *)malloc(sizeof(agN));    // alocando espaço na memoria

    printf("\n\t----- Adicionando Nomes -----");
    printf("\n\tDigite um nome: ");
    scanf("%s", nvNome->nome);              //nvNome tem conteudo de nome
    nvNome->prox = inicio->prox;            //nome é inserido entre a celula inicio e o seguinte, tudo isso para inicio != null
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
    while ((q != NULL) && (strcmp(q->nome, nome) != 0))  //busca o nome que o usuario quer remover
    {
        p = q;
        q = q->prox;
    }
    if (q != NULL)  //se o nome existir, remove da lista
    {
        p->prox = q->prox;
        free(q);                                    //libera espaco na memoria
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
    for (listar = inicio->prox; listar != NULL; listar = listar->prox) //lista recebe o valor que está na lista,
    {                                                                  //se ela for != de NULL, tem algo lá dentro, então listar->prox é uma lista
        printf("\n\tNome: %s\n", listar->nome);                        //imprime nome da lista
    }
}
