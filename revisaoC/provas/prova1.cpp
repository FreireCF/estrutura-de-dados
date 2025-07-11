/* Escreva um programa em C que receba o valor de uma compra e a quantia paga pelo cliente.
    Se a quantia paga for menor que o valor da compra, exiba uma mensagem de erro.
    Se for igual, informe que não há troco.
    Se for maior, calcule e exiba o troco usando a menor quantidade possível de cédulas disponíveis (R$50, R$20, R$5 e R$2).
    Caso haja troco restante menor que R$2, informe o valor que será dado em moedas. */

#include <stdio.h>

int main(){
    int cedulas[4] = {50, 20, 5, 2};
    int qdtCedulas [4] = {0};    
    int valorPago, valorCompra, troco; 

    printf("Valor da compra: ");
        scanf("%d",&valorCompra);

    printf("Valor recebido pelo cliente: ");
        scanf("%d",&valorPago);

    if(valorCompra == valorPago){
        printf("Não precisa de troco!");
    } else if (valorCompra > valorPago){
        printf("Valor pago pelo cliente  é insuficiente!");
    } else {
        troco = valorPago - valorCompra;
       
        for (int i = 0; i<4; i++){
            qdtCedulas[i] = troco/cedulas[i]; //saber quantas cedulas serão necessárias de um devido valor; Ex: troco==60 60/50 = 1 e alguma coisa e sobra 10. ou seja, usaremos 1 nota de 50 e passamos para a proxima verificação com outras notas.
            troco = troco%cedulas[i]; //mesma lógica mas agora estamos calculando o troco atraves do resto. 
        }
        printf("Notas para o troco: ");
        for (int i=0; i<4;i++){
            printf("\n%d nota(s) de R$ %d", qdtCedulas[i], cedulas[i]);
        }
    }
    if (troco>0){
        printf("R$ %d em moedas",troco);
    }
}