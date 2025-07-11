#include <stdio.h>
#include <stdlib.h>
#include <random>

typedef struct node{
  int valor;
  struct node *dir;
  struct node *esq;
} Node;

Node *criarNode(int valor){
  Node *n = new Node;
  n->valor = valor;
  n->esq = NULL;
  n->dir = NULL;

  return n;
}

Node *trocarRaiz(Node *velhaRaiz, int num){
  Node *novaRaiz = criarNode(5);

  if (velhaRaiz->valor < novaRaiz->valor){
    novaRaiz->dir = velhaRaiz->dir;
    velhaRaiz->dir = NULL;
    novaRaiz->esq = velhaRaiz;
  }

  if (velhaRaiz->valor > novaRaiz->valor){
    novaRaiz->esq = velhaRaiz->esq;
    velhaRaiz->esq = NULL;
    novaRaiz->dir = velhaRaiz;
  }
  return novaRaiz;
}

Node *buscar(Node *n, int num){
  if (n == NULL)
    return NULL;
  if (n->valor == num)
    return n;
  if (num < n->valor)
    return buscar(n->esq, num);
  else
    return buscar(n->dir, num);
}

void inserirNode(Node *n, int num){
  if (num < n->valor){
    if (n->esq == NULL){
      n->esq = criarNode(num);
    }
    else{
      inserirNode(n->esq, num);
    }
}

  if (num > n->valor){
    if (n->dir == NULL){
      n->dir = criarNode(num);
    }
    else{
      inserirNode(n->dir, num);
    }
  }
}

void remover(Node *raiz, int num){
  Node *filho = raiz;
  Node *pai;

  do{
    pai = filho; // salva o elemento anterior
    if (num < filho->valor)
      filho = filho->esq;
    else if (num > filho->valor)
      filho = filho->dir;
  } while (filho != NULL && filho->valor != num);

  if (filho != NULL){
    if (filho->esq == NULL && filho->dir == NULL){ // sem filhos
      if (pai->esq == filho)
        pai->esq = NULL;
      if (pai->dir == filho)
        pai->dir = NULL;
      }

    if (filho->esq != NULL && filho->dir == NULL){ // filho na esquerda
      if (pai->esq == filho)
        pai->esq = filho->esq;
      if (pai->dir == filho)
        pai->dir = filho->esq;
      }

      if (filho->esq == NULL && filho->dir != NULL){ // filho na direita
        if (pai->esq == filho)
          pai->esq = filho->dir;
        if (pai->dir == filho)
          pai->esq = filho->dir;
      }

      if (filho->esq != NULL && filho->dir != NULL){ // filho na direita e esquerda
        if (filho->esq->dir == NULL){
          filho->valor = filho->esq->valor; // apenas troca os valores, n precisa atualizar ponteiros
          filho->esq = NULL;
        } else {
            Node *p = filho->esq;
            Node *aux = p;

            while (p->dir != NULL){
              aux = p;
              p = p->dir;
            }
              aux->dir = NULL;
              filho->valor = p->valor;
        }
    }
  }
}

void imprimir(Node *n, int tab = 0){
  if (n == NULL)
    return;

  imprimir(n->dir, tab + 1);
  for (int i = 0; i < tab; i++){
    printf("\t");
  }
  printf("%d\n", n->valor);
  imprimir(n->esq, tab + 1);
}

int main(){

  Node *raiz = criarNode(20);

  // inserirNode(raiz, 20);
  inserirNode(raiz, 10);
  inserirNode(raiz, 5);
  inserirNode(raiz, 15);
  inserirNode(raiz, 30);
  inserirNode(raiz, 25);
  inserirNode(raiz, 35);

  imprimir(raiz);

  // Node *novaRaiz = trocarRaiz(raiz, 5);
  // inserirNode(novaRaiz, 4);
  // imprimir(novaRaiz);
  // remover(novaRaiz, 3);
  // imprimir(novaRaiz);

  // remover(raiz, 2);
  // printf("\nApós remorção: \n\n");
  // imprimir(raiz);

  // remover(raiz, 1);
  // printf("\nApós remorção: \n\n");
  // imprimir(raiz);

  Node *busc = buscar(raiz, 14);

  if (busc == NULL)
    printf("\nNúmero não encontrado\n");
  else
    imprimir(busc);
}