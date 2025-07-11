#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elemento;
    struct node *prox;
} Node;

void inserir(Node **lista, int newElemento){
    Node *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = newElemento;
        novoNo->prox = *lista;
        *lista = novoNo;
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void imprimir(Node **lista){
    Node *aux = *lista;
    while(aux->prox!=0){
        printf("%d -> ",aux->elemento);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    Node *lista = NULL;
    inserir(&lista, 4);
    inserir(&lista, 3);
    inserir(&lista, 2);
    inserir(&lista, 1);
    inserir(&lista, 0);
    imprimir(&lista);
}