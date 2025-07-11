#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

typedef struct Lista {
    float x, y;  
    struct Lista *prox;
} Lista; 

Lista *primeiroItem=NULL; 

void adicionarElemento (int x){ 
    Lista *p = (Lista*) malloc(sizeof(Lista));
    p->x = x;
    p->prox = primeiroItem; 
    primeiroItem = p; 
}

void imprimirLista(){
  Lista *aux = primeiroItem; 
    while(aux!=NULL){
      printf("\n(x: %.2f, y: %.2f)", aux->x, aux->y);
      aux = aux->prox;
    }
    printf("\n");
}

void inicia_vetor(int *vetor, int n) {
  srand(clock()); //seed (clock: tempo atual) para gerar os números aleatórios
    for (int i = 0; i < n; i++) {
      vetor[i] = (abs(rand())%100);
  }
}

void imprimir(int *vetor, int n) {
  printf("[");
    for (int i = 0; i < n; i++) {
      printf(" %d ", vetor[i]);
  }
  printf("]\n");
  printf("\n");
}

void troca(int *vetor, int i, int j) {
  int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
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

int main() {
    int n = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int* vetor = (int*) malloc(n * sizeof(int));    

    inicia_vetor(vetor, n);
    printf("\nVetor gerado: ");
    imprimir(vetor, n);

    insertionSort(vetor, n);

    printf("\nVetor ordenado: ");
    imprimir(vetor, n);
}