#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *Teste (char *s1, const char *s2) {
char *aux=s1;
while (*s1) s1++;
for ( ; (*s1 = *s2) != '\0' ; s1++, s2++);
return aux;
}

int main(){

    char s1[30], s2[30];

    printf("\nDigite uma palavra: ");
    scanf("%s", s1);
    printf("Digite outra palavra: ");
    scanf("%s", s2);


    //teste = Teste(s1, s2);
    printf("Teste eh: %s\n", Teste(s1, s2));

    //printf("Copiando *s1 para *s2: %s\n", strcpy(s2, s1));

    return 0;
}

/*Programa de teste para ver a saída da funcao Teste.*/