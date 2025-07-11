/*Crie uma função chamada somaDigitos que recebe um número inteiro positivo e retorna a soma de seus dígitos.*/

#include <stdio.h> 

int somaDigitos(int num){
    int soma;

    while(num>0){
        soma += num%10;
        num /= 10;
    }
    return soma;
}

int main(){
    int num, soma;
    printf("Digite um número para receber a soma dos seus dígitos: ");
        scanf("%d",&num);

    if (num<0){
        printf("Digite um número maior que ou igual a 0");
    } else {
        soma = somaDigitos(num);
        printf("A soma dos dígitos de %d é: %d", num, soma);
    }
}