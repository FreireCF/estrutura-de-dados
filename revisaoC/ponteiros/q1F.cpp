/*2. Alteração de Valores Usando Ponteiros

Crie uma struct chamada Produto, contendo:

    nome (string de até 50 caracteres)
    preco (float)

Implemente uma função atualizarPreco() que recebe um ponteiro para Produto e um novo preço. A função deve modificar o preço do produto diretamente.

No main():

    Peça ao usuário para inserir os dados do produto.
    Chame atualizarPreco() para modificar o preço.
    Exiba os dados do produto antes e depois da alteração.*/

#include <stdio.h>

typedef struct {
    char name[50];
    float price;
} Product;

Product products;

int alterarPreco(float *price, float *newPrice){
    printf("Type the new price: ");
        scanf("%d",&oldPrice);
    
    price = newPrice;

}