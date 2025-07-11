#include <math.h>
#include <stdio.h>
#include <time.h>
#include <random>

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

void selectionSort(int *vetor, int n) {
    int i, j, menor;
    for (i=0; i<n-1; i++) {
        menor = i;
        for (j = i+1; j<n; j++) { //i+1 para n comparar o i com ele mesmo
            if (vetor[j] < vetor[menor])
                menor = j;
        }
        if(menor!=i){ //nao realizar a troca com ele mesmo
        troca(vetor, i, menor);
        }
    }
}

int main(){
  int n = 0;
  printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
  int* vetor = (int*) malloc(n * sizeof(int));    

  inicia_vetor(vetor, n);
  printf("\nVetor gerado: ");
  imprimir(vetor, n);

  selectionSort(vetor, n);

  printf("\nVetor ordenado: ");
  imprimir(vetor, n);
  free(vetor);
}