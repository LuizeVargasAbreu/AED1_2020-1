#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *palavrasSeparadas(char linha[80]);

int main(){
    
    char linha[80];

    printf("\nDigite uma frase: ");
    scanf("%[^\n]", linha);

    palavrasSeparadas(linha);

    return 0;
}

char *palavrasSeparadas(char linha[80]){

    char *palavra;

    palavra = (char *) malloc(80 * sizeof(char));

    palavra = strtok(linha, " ");
    while (palavra != NULL)
    {
        printf("%s\n", palavra);
        palavra = strtok(NULL, " ");
    }
    free(palavra);
    return palavra;
}