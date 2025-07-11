#include <stdio.h>

int main(){
    int num, primeiro = 0, atual = 1, proximo;

    printf("Digite um número: ");
        scanf("%d",&num);
    
    if(num<=0){
        printf("Digite um número maior que 0");
    } 
    printf("%d númeor na seq. de fibonacci: ",num);
    for(int i = 0; i<=num-1; i++){
        printf(" %d ",primeiro);
        proximo = primeiro + atual;
        primeiro = atual;
        atual = proximo;
    }
}