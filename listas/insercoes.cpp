#include <stdio.h>
#include <stdlib.h> 

typedef struct node{
    int elemento;
    struct node *prox;
} Node;

void inserirInicio(Node **lista, int novoElemento){
    Node *novoNo= (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        novoNo->prox = *lista;
        *lista = novoNo;
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void inserirFinal(Node **lista, int novoElemento){
    Node *aux, *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        novoNo->prox = NULL;
        if(*lista == NULL){
            *lista = novoNo;
        } else {
            aux = *lista;
            while(aux->prox!=NULL){
                aux = aux->prox;
            }
            aux->prox = novoNo;
        }
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void inserirMeio(Node **lista, int novoElemento, int anterior){ //iremos inserir depois do anterior
    Node *aux, *novoNo = (Node*) malloc(sizeof(Node));

    if(novoNo){
        novoNo->elemento = novoElemento;
        //caso a lista esteja vazia, podemos inserir normalmente
        if(*lista==NULL){
            novoNo->prox = NULL;
            *lista = novoNo;
        } else {
            aux = *lista;
            while(aux->elemento!=anterior && aux->prox!=NULL){
                aux = aux->prox;
            }
            novoNo->prox = aux->prox;
            aux->prox = novoNo;
        }
    } else {
        printf("\nErro ao alocar memória!");
    }
}

void imprimirLista(Node **lista){
    Node *aux = *lista;
    printf("\nLista atual: ");
    printf("\n[");
    while(aux!=NULL){
        printf(" %d ",aux->elemento);
        aux = aux->prox;
    }
    printf("]\n");
}

int pedirElemento(){
    int novoElemento;
    printf("\nDigite um número inteiro para inserir na lista: ");
        scanf("%d",&novoElemento);
    return novoElemento;
}

int menu(){
    int opc;
    printf("\n----------------MENU----------------");
    printf("\n| [0] - Encerrar programa          |");
    printf("\n| [1] - Inserir no início da lista |");
    printf("\n| [2] - Inserir no meio da lista   |");
    printf("\n| [3] - Inserir no final da lista  |");
    printf("\n| [4] - Ver a lista                |");
    printf("\n------------------------------------");
    printf("\nDigite sua opção: ");
        scanf("%d",&opc);
    return opc;
}

int main(){
    Node *lista = NULL;
    int opc = -1, elemento = 0;
    
    while(opc!=0){
        opc = menu();

        switch (opc) {
        case 0:
            printf("\nEncerrando programa");
            printf("\n");
            break;
        case 1:
            elemento = pedirElemento();
           inserirInicio(&lista, elemento);
            break;
        case 2:
            elemento = pedirElemento();
            imprimirLista(&lista);
            int ant;
            printf("\nDeseja inserir depois de qual elemento?");
                scanf("%d",&ant);
            inserirMeio(&lista, elemento, ant);
            break;
        case 3:
            elemento = pedirElemento();
            inserirFinal(&lista, elemento);
            break;
        case 4:
            imprimirLista(&lista);
            break;
        default:
            printf("\nOpção inválida!");
            break;
        }
    }
}