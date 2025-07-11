#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elemento;
    struct node *prox;
} Node;

void inserirInicio(Node **lista, int novoElemento){
    Node *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        novoNo = *lista;
        *lista = novoNo;
    } else {
        printf("\nErro ao alocar memória");
    }
}

void imprimir(Node **lista){
    Node *aux = *lista;

    while(aux!=NULL){
        printf("%d -> ",aux->elemento);
        aux = aux->prox;
    }
}

int main(){
    Node *lista = NULL;

    inserirInicio(&lista, 0);
    inserirInicio(&lista, 1);
    inserirInicio(&lista, 2);
    imprimir(&lista);
}