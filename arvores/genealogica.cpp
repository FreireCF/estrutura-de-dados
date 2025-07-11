#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[100];
    pessoa *pai; //esquerda
    pessoa *mae; //direita
}Pessoa;

Pessoa *criarPessoa(const char nome[], Pessoa *pai, Pessoa *mae){
    Pessoa *p = new Pessoa;
    
    strcpy(p->nome, nome);
    p->pai = pai;
    p->mae = mae;

    return p;
}

void imprimir(Pessoa *p, int tab=0) {
    if (p == NULL) return;

    imprimir(p->pai, tab + 1);
    for (int i = 0; i < tab; i++) {
        printf("\t");
    }
    printf("%s\n", p->nome);
    imprimir(p->mae, tab + 1);
}

int main(){
    Pessoa* avo1 = criarPessoa("Alberto", NULL, NULL);
    Pessoa* avo2 = criarPessoa("Marta", NULL, NULL);
    Pessoa* avo3 = criarPessoa("Luiz", NULL, NULL);
    Pessoa* avo4 = criarPessoa("Beatriz", NULL, NULL);

    Pessoa* pai = criarPessoa("Carlos", avo1, avo2);
    Pessoa* mae = criarPessoa("Ana", avo3, avo4);

    Pessoa* filho = criarPessoa("João", pai, mae);

    imprimir(filho, 0);
}