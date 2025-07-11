#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct No{
    int num;
    struct No *prox;
    struct No *ant;
}No;


No* criaNo(int num){
    No *no = (No*) malloc(sizeof(No));

    no->num = num;
    no->prox = NULL;
    no->ant = NULL;

    return no;
}

void insereElementoLista(No** pHead, No** pTail, int num){
    if((*pHead) == NULL){
        (*pHead) = criaNo(num);
        (*pTail) = (*pHead);
        return;
    }

    No *aux = (*pTail);
    (*pTail) = criaNo(num);
    (*pTail)->ant = aux;
    aux->prox = (*pTail);
}

void imprimeListaA(No *aux){
    if(aux == NULL){
        printf("Lista vazia");
        return;
    }

    while (aux != NULL){
        printf("%d -> ", aux->num);
        aux = aux->prox;
    }
    printf("Fim");
}

void imprimeListaZ(No *aux){

    if(aux == NULL){
        printf("Lista vazia");
        return;
    }

    while (aux != NULL){
        printf("%d -> ", aux->num);
        aux = aux->ant;
    }
    printf("Fim");
}

void insertionSort(int vetor[], int n) {
    for (int i = 1; i < n; i++) {
        int elementoAtual = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > elementoAtual) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = elementoAtual;
    }
}

void trocaElementos(No **atual, No **menor, No **ptrHead, No **ptrTail){
    if((*atual)->ant == NULL){
        (*ptrHead) = (*menor);
        //Atual = 5 e Menor = 3

        No *proxMenor = (*menor)->prox; // 4
        No *antMenor = (*menor)->ant; // 5 

        No *proxAtual = (*atual)->prox; // 3
        No *antAtual = (*atual)->ant; // NULL

        if(antMenor != (*atual)){
            (*atual)->ant = antMenor;
            antMenor->prox = (*atual);
        }
        else{
            (*atual)->ant = (*menor);
            (*atual)->prox = proxMenor;
            proxMenor->ant = (*atual);
        }

        if(proxAtual != (*menor)){
            (*menor)->prox = proxAtual;
            proxAtual->ant = (*menor);
        }
        else{
            (*menor)->prox = (*atual);
            (*menor)->ant = antAtual;
        }
    }
}

No* insertionSort(No *ptrHead, No *ptrTail){
    for (No *i = ptrHead->prox; i != NULL; i = i->prox){
        No *elementoAtual = i;
        No *j = i->ant;

        while (j != NULL && j->num > elementoAtual->num) {
            //atualizar os ponteiros
            // trocaElementos(j, elementoAtual);
            j = j->ant;
        }
        // trocaElementos();
    }
}

void preencheLista(int n, No** phead, No** ptail){
    for (int i = 0; i < n; i++)
    {
        int numeroAleatorio = rand() % 100;
        insereElementoLista(phead, ptail, numeroAleatorio);
    }
}

int main(){
    srand(time(NULL));
    No *pHead = NULL;
    No *pTail = NULL;

    preencheLista(5, &pHead, &pTail);
    imprimeListaA(pHead);
    printf("\n");
    imprimeListaZ(pTail);

    return 0;
}