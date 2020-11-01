#include<stdio.h> 
#include<stdlib.h>

int F1 ( unsigned int n)
{
if(n==0) return n;
int i , j;
for ( i = j = 1; i<2 *n-1 ; i+=2, j +=i);
return j;
}

int F2 (int n){
    int i, j;
    if(n == 0)
        return n;

    for(i = j = 1; i < n; i++){
        for(int k = 0; k < n; k++){
            j++;
        }
        j++;
    }
    printf("F2 eh: %d\n", j);
    return j;
}

int main(){

    int n;
    //int n = 10;

    printf("Informe um valor pra n: ");
    scanf("%d", &n);

    printf("F1 eh: %d\n", F1(n));
    F2(n);
    return 0;
}
