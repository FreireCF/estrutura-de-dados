/*Uma loja deseja armazenar informações de seus produtos. Crie uma struct chamada Produto, que deve conter:

    Nome do produto (máximo 50 caracteres)
    Código do produto (inteiro)
    Preço (float)

O programa deve solicitar ao usuário os dados de um produto e, em seguida, exibir essas informações na tela.*/

#include <stdio.h>

typedef struct {
    char name[50];
    int code;
    float price;
} Product;

int main(){
Product products;

printf("Cadastro de produtos\n");
printf("What is the name? ");
    scanf("%s",&products.name);

printf("Type the code: ");
    scanf("%d",&products.code);

printf("Type the price: ");
    scanf("%f",&products.price);

printf("Name: %s\n",products.name);
printf("Code: %d\n",products.code);
printf("Price: $ %.2f\n",products.price);
}