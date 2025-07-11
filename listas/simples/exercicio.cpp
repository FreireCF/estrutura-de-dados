//gere uma lista C com os elementos das listas A e B
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int elemento; 
    struct node *prox;
} Node;

typedef struct{
    Node *inicio;
    int tamanho;
} Queue;

void criarLista(Queue *lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirInicio(Queue *lista, int novoElemento){
    Node *novoNo= (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
        lista->tamanho++; //incremento do tamanho da lista a cada novoNo 
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void inserirFinal(Queue *lista, int novoElemento){
    Node *aux, *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        novoNo->prox = NULL;
        
        if(lista->inicio==NULL){
            lista->inicio = novoNo;
        } else {
            aux = lista->inicio;
            while(aux->prox!=NULL){
                aux = aux->prox;
            }
            aux->prox = novoNo;
        }
        lista->tamanho++;
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void imprimirLista(Queue lista){ //como só iremos imprimir, podemos usar uma cópia da lista
    Node *aux = lista.inicio;

    printf("\nA lista atual possui %d elementos: ",lista.tamanho);
    printf("\n[");

    while(aux!=NULL){
        printf(" %d ->",aux->elemento);
        aux = aux->prox;
    }
    printf("]\n");
}

void randomLista(Queue *lista, int qnt){
    int num=0;
    for(int i=0; i<qnt; i++){
        num = abs(rand() % 100);
        inserirInicio(lista, num);
    }
}

void criarListaC(Queue *destino, Queue origem){
    Node *aux = origem.inicio;
    while(aux != NULL){
        inserirFinal(destino, aux->elemento);
        aux = aux->prox;
    }
}

int main(){
    Queue listaA, listaB, listaC;
    criarLista(&listaA); 
    criarLista(&listaB);
    criarLista(&listaC);
    
    srand(time(NULL));
    randomLista(&listaA, 5);
    randomLista(&listaB, 5);

    printf("\nLista A:\n");
    imprimirLista(listaA);

    printf("\nLista B:\n");
    imprimirLista(listaB);
    
    criarListaC(&listaC, listaA);
    criarListaC(&listaC, listaB);
    printf("\nLista C (combinação de A e B): ");
    imprimirLista(listaC);   
    return 0;
}