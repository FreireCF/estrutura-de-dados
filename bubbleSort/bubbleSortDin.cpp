#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int elemento;
    struct node *prox;
    struct node *ant;
}Node;

void inserirInicio(Node **lista, int novoElemento){
    Node *novoNo = new Node;

    if(novoNo){
        novoNo->elemento = novoElemento;
        novoNo->prox = *lista;
        *lista = novoNo;
    } else {
        printf("\nErro ao alocar memória");
    }
}

void imprimir(Node **lista){
    Node *aux = *lista;

    printf("\n");
    while(aux!=NULL){
        printf("%d -> ",aux->elemento);
        aux = aux->prox;
    }
    printf("\n");
}


void troca(Node **lista, Node *e1, Node *e2) {
    if (e1 == NULL || e2 == NULL || e1 == e2) return;

    // Garante que e1 vem antes de e2 na lista
    if (e1->prox == e2 || e2->prox == e1) {
        // São vizinhos, tratamos esse caso separadamente
        if (e2->prox == e1) {
            Node *tmp = e1;
            e1 = e2;
            e2 = tmp;
        }

        Node *prev = e1->ant;
        Node *next = e2->prox;

        if (prev != NULL)
            prev->prox = e2;
        else
            *lista = e2;

        if (next != NULL)
            next->ant = e1;

        e2->ant = prev;
        e2->prox = e1;
        e1->ant = e2;
        e1->prox = next;
        return;
    }

    Node *e1_ant = e1->ant;
    Node *e1_prox = e1->prox;
    Node *e2_ant = e2->ant;
    Node *e2_prox = e2->prox;

    if (e1_ant != NULL)
        e1_ant->prox = e2;
    else
        *lista = e2;

    if (e1_prox != NULL)
        e1_prox->ant = e2;

    if (e2_ant != NULL)
        e2_ant->prox = e1;
    else
        *lista = e1;

    if (e2_prox != NULL)
        e2_prox->ant = e1;

    // Troca os ponteiros de e1 e e2
    e1->ant = e2_ant;
    e1->prox = e2_prox;
    e2->ant = e1_ant;
    e2->prox = e1_prox;
}

void gerarAleatorios(Node **lista, int qnt){
     for(int i=0; i<qnt; i++){
        inserirInicio(lista, random()%100);
    }
}

void bubbleSort(Node **lista) {
    if (*lista == NULL) return;

    bool trocou;
    do {
        trocou = false;
        Node *atual = *lista;

        while (atual->prox != NULL) {
            if (atual->elemento > atual->prox->elemento) {
                troca(lista, atual, atual->prox);
                trocou = true;

                if (atual->ant != NULL)
                    atual = atual->ant;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

int main(){
    Node *lista = NULL;

    gerarAleatorios(&lista, 10);

    imprimir(&lista);
    
    bubbleSort(&lista);
    printf("\nApós ordenação: ");
    
    imprimir(&lista);
}