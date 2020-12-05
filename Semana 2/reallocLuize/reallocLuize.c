#include<stdio.h>
#include<stdlib.h>
int main(){

    int *p, *inicio, qtd;

    printf("\n- Informe a quantidade de numeros que o usuario ira digitar: ");
    scanf("%d", &qtd);

    //ALOCANDO ESPACO NA MEMORIA
    p = (int *) malloc(qtd * sizeof(int));
    inicio = p;

    //VERIFICANDO SE HÁ ESPACO LIVRE NA MEMORIA
    if(!p){
        printf("Erro! Falta de memoria.");
        return -1;
    }
    
    //INFORMANDO OS VALORES
    printf("- Informe %d valores: ", qtd);
    for (int i = 0; i < qtd; i++, p++)
    {
        scanf("%d", p);
    }

    //IMPRIMINDO OS VALORES
    p = inicio;
    printf("- Os valores digitados pelo usuario foram: ");
    for (int i = 0; i < qtd; i++, p++)
    {
        printf("%d ", *p);
    }

    //REALOCANDO A MEMÓRIA
    printf("\nInforme a quantidade de numeros para realocar a memoria: ");
    scanf("%d", &qtd);

    p = inicio;
    p = (int *) realloc(p, qtd * sizeof(int));
    
    //VERIFICANDO SE HÁ ESPACO LIVRE NA MEMORIA
    if(!p){
        printf("Erro! Falta de memoria.");
        return -1;
    }

    //INFORMANDO OS VALORES REALOCADOS NA MEMORIA
    printf("- Informe %d valores: ", qtd);
    for (int i = 0; i < qtd; i++, p++)
    {
        scanf("%d", p);
    }

    //IMPRIMINDO OS VALORES REALOCADOS NA MEMORIA
    p = inicio;
    printf("- Os valores digitados pelo usuario foram: ");
    for (int i = 0; i < qtd; i++, p++)
    {
        printf("%d ", *p);
    }

    //LIBERANDO A MEMORIA
    free(p);

    return 0;
}
