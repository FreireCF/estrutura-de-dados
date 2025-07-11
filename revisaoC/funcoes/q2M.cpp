/*  Médio: Função para verificar se um número é primo

Implemente uma função chamada ehPrimo que recebe um número inteiro e retorna 1 se for primo ou 0 se não for. */

#include <stdio.h> 
#include <stdbool.h>

bool ehPrimo(int num){
    int cont=0;
    
    if (num <=0){
        printf("Digite um número maior que 0");
    }
    for(int i=2; i<=num/2; i++){
        if (num%i==0) {
            cont++;
        }
    }
        if (cont!=0){
            return false;
        } else {
            return true;
        }
    }

int main(){
    int numm, testePrimo;
    printf("Digite um número: ");
        scanf("%d",&numm);

    testePrimo = ehPrimo(numm);
    if (testePrimo == true){
        printf("O número é primo");
    } else {
        printf("O número não é primo");
    }
}