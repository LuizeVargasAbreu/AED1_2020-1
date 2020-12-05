#include<stdio.h>
#include<stdlib.h>

int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int *colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int n);

int main(){

 int op, m, n, **mat = NULL, *vet = NULL, ncoluna = 0;

 do{
    printf("\n\t----- CRIANDO UMA MATRIZ -----\n");
    printf("\t1 - Criar uma Matriz \n\t2 - Ler uma Matriz \n\t3 - Soma da Matriz"
           "\n\t4 - Imprimir uma Coluna da Matriz \n\t5 - Imprimir a Matriz \n\t6 - Sair do Programa\n");
    printf("\n\tDigite a opcao desejada: ");
    scanf("%d", &op);

    switch(op){
    case 1:
        //CRIAR MATRIZ
        printf("\nInforme o numero de linhas: ");
        scanf("%d", &m);
        printf("Informe o numero de colunas: ");
        scanf("%d", &n);
        mat = criaMatriz(m, n);
        break;
    case 2:
        //LER MATRIZ
        leiaMatriz(mat, m, n);
        break;
    case 3:
        //SOMA MATRIZ
        somaMatriz(mat, m, n);
        break;
    case 4:
        //IMPRIMI VETOR DE UMA COLUNA DA MATRIZ
        vet = colunaMatriz(mat, m, n, ncoluna);
        imprimeVetor(vet, m);
        break;
    case 5:
        //IMPRIMI MATRIZ
        imprimeMatriz(mat, m, n);
        break;
    case 6:
        //SAIR
        liberaMatriz(mat, ncoluna);
        printf("\nSaindo!\n");
        break;
    default:
        printf("\nOpcao invalida! Tente novamente.\n");
        break;
    }

 }while(op != 6);

return 0;
}

int **criaMatriz(int m, int n){

    int **matriz = (int **) malloc(m * sizeof(int *));
    if(!matriz){
        printf("Erro! Falta de memoria.");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        matriz[i] = (int *) malloc(n * sizeof(int));
    }
    return matriz;
}

void leiaMatriz(int **mat, int m, int n){

    printf("\nInforme os elementos da matriz: ");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

int somaMatriz(int **mat, int m, int n){

    int smMatriz = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            smMatriz += mat[i][j];
        }
    }
    printf("\nA soma da matriz eh: %d.\n", smMatriz);
    return smMatriz;
}

int *colunaMatriz(int **mat, int m, int n, int ncoluna){

    printf("\nInforme o numero da coluna que deseja ver: ");
    scanf("%d", &ncoluna);
    ncoluna = ncoluna - 1;

    int *vet = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j == ncoluna){
                vet[i] = mat[i][j];
            }
        }
    }
    printf("\nA vetor da coluna %d eh: ", ncoluna + 1);
    return vet;
}

void liberaMatriz(int **mat, int ncoluna){

    for(int i = 0; i < ncoluna; i++){
        free(mat[i]);
    }
    free(mat);
}

void imprimeMatriz(int **mat, int m, int n){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void imprimeVetor(int *vet, int n){

    for(int j = 0; j < n; j++){
        printf("%d\t", vet[j]);
    }
    printf("\n");
    free(vet);
}
