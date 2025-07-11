/*Difícil: Função para inverter uma string

Crie uma função chamada inverterString que recebe uma string e inverte seus caracteres sem usar bibliotecas como string.h. */

#include <stdio.h>

void inverterString(char palavra[]) {
    int i = 0, j;
    
    while (palavra[i] != '\0') {
        i++;
    }
    j = i - 1; 
    
    for (int k = 0; k < j; k++, j--) {
        char temp = palavra[k];
        palavra[k] = palavra[j];
        palavra[j] = temp;
    }
}

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inverterString(palavra);
    
    printf("String invertida: %s\n", palavra);
}