/* Fácil: Função para calcular o quadrado de um número

Crie uma função chamada quadrado que recebe um número inteiro como parâmetro e retorna o quadrado desse número. */

#include <stdio.h>

float calcularQuadrado(float num){
    float numQuad = num*num;
    return numQuad;
}

int main(){
    float num;
    printf("Digite um número para receber seu quadrado: ");
        scanf("%f",&num);

    float quadrado = calcularQuadrado(num);
    printf("O quadrado de %.2f é %.2f\n",num, quadrado);
}