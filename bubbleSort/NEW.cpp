#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int elemento;
  struct node *prox = NULL;
  struct node *ant = NULL;
} Node;

typedef struct {
  Node *inicio = NULL;
  Node *fim = NULL;
  int tamanho = 0;
} Lista;

void inserirInicio(Lista *l, int num) {
  Node *novo = new Node;
  novo->elemento = num;
  novo->ant = NULL;

  if (l->tamanho == 0) {
    l->inicio = novo;
    l->fim = novo;
  } else {
    novo->prox = l->inicio;
    l->inicio = novo;
  }
  l->tamanho++;
}

void inserirFim(Lista *l, int num) {
  Node *novo = new Node;
  novo->elemento = num;
  novo->ant = l->fim;

  if (l->tamanho == 0) {
    l->inicio = novo;
    l->fim = novo;
    novo->ant = NULL;
  } else {
    l->fim->prox = novo;
    l->fim = novo;
  }
  novo->prox = NULL;
  l->tamanho++;
}

void troca(Lista *l, Node *e1, Node *e2) {
    if (e1 == NULL || e2 == NULL || e1 == e2) return;

    // Garante que e1 vem antes de e2
    if (e2->prox == e1) {
        Node *tmp = e1;
        e1 = e2;
        e2 = tmp;
    }

    if (e1->prox == e2) {
        // São vizinhos
        Node *anterior = e1->ant;
        Node *proximo = e2->prox;

        if (anterior != NULL)
            anterior->prox = e2;
        else
            l->inicio = e2;

        if (proximo != NULL)
            proximo->ant = e1;
        else
            l->fim = e1;

        e2->ant = anterior;
        e2->prox = e1;

        e1->ant = e2;
        e1->prox = proximo;
        return;
    }

    // São nós distantes
    Node *e1_ant = e1->ant;
    Node *e1_prox = e1->prox;
    Node *e2_ant = e2->ant;
    Node *e2_prox = e2->prox;

    // Atualiza ligações externas
    if (e1_ant != NULL)
        e1_ant->prox = e2;
    else
        l->inicio = e2;

    if (e1_prox != NULL)
        e1_prox->ant = e2;
    else
        l->fim = e2;

    if (e2_ant != NULL)
        e2_ant->prox = e1;
    else
        l->inicio = e1;

    if (e2_prox != NULL)
        e2_prox->ant = e1;
    else
        l->fim = e1;

    // Troca os ponteiros internos
    e1->ant = e2_ant;
    e1->prox = e2_prox;
    e2->ant = e1_ant;
    e2->prox = e1_prox;
}

void gerarAleatorios(Lista *lista, int qnt){
  for(int i=0; i<qnt; i++){
    inserirInicio(lista, random()%100);
  }
}

void bubbleSort(Lista *lista) {
  if (lista->inicio == NULL) return;

  bool trocou;
  do {
    trocou = false;
    Node *atual = lista->inicio;

    while (atual != NULL && atual->prox != NULL) {
      if (atual->elemento > atual->prox->elemento) {
        Node *proximo = atual->prox;
        troca(lista, atual, proximo);
        trocou = true;

        // após a troca, atual agora está no prox do proz
        // volta para comparar com o novo prox
        if (proximo->ant)
          atual = proximo->ant;
        else
          atual = proximo;
      } else {
          atual = atual->prox;
      }
    }
  } while (trocou);
}


void imprimir(Lista *l){
    Node *aux = l->inicio; ;

    printf("\n");
    while(aux!=NULL){
        printf("%d -> ",aux->elemento);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    Lista *lista = new Lista;

    gerarAleatorios(lista, 10);

    imprimir(lista);

    //bubbleSort(lista);
    troca(lista, lista->inicio, lista->fim);
    printf("\nApós ordenação: troca ");
    
    imprimir(lista);
}