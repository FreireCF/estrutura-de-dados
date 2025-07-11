#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elemento;
    struct node *prox;
} Node;

void inserirInicio(Node **lista, int novoElemento){
    Node *novoNo = malloc(sizeof(Node));

    if (novoNo){
        novoNo->elemento = novoElemento; //o elemento no novoNo é o elemento passado como parâmetro
        novoNo->prox = *lista; //o próximo elemento do novo nó é o início da lista atual
        *lista = novoNo; // o início da lista atual, passa a ser o elemento que acabou de ser inserido
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void inserirFinal(Node **lista, int novoElemento){
    Node *aux, *novoNo = malloc(sizeof(Node));
    
    if (novoNo){
        novoNo->elemento = novoElemento;
        novoNo->prox = NULL; //como quero inserir no final, o próximo do novo elemento será NULL
        //temos que verificar se a lista está vazia, caso esteja, basta atribuir o valor do novo elemento para ela
        if(*lista == NULL){
            *lista = novoNo;
            //se a lista não estiver vazia, precisamos chegar no último elemento
        } else {
            aux = *lista; //ponteiro auxiliar para o primeiro elemento da lista, assim, não perderemos nossa lista ao percorrer até o último elemento
            while(aux->prox!=NULL){
                aux = aux->prox;
            }
            aux->prox = novoNo;
        }
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void inserirMeio(Node **lista, int novoElemento, int anterior){ 
  Node *aux, *novoNo = malloc(sizeof(Node));
  
  if(novoNo){
    novoNo->elemento = novoElemento;

    if(*lista == NULL){ //inserindo na lista vazia
      *lista = novoNo;
      novoNo->prox = NULL;
    } else{ //lista não vazia (devemos percorrer até encontrar a referência passada como parâmetro e inserir depois dela)
      aux = *lista;
      while(aux->elemento == anterior && aux->prox!=NULL){
        aux = aux->prox;
      }
      novoNo->prox = aux->prox;
      aux->prox = novoNo;
    }
  } else {
    printf("\nErro ao alocar memória");
  }
}

int main(){
    
}