/* 3. Cálculo de Área e Perímetro de um Retângulo

Crie uma struct chamada Retangulo que armazene:

    Largura (float)
    Altura (float)

O programa deve conter:

    Uma função criarRetangulo(float largura, float altura) que recebe valores e retorna uma struct Retangulo.
    Uma função calcularArea(Retangulo r) que retorna a área do retângulo.
    Uma função calcularPerimetro(Retangulo r) que retorna o perímetro do retângulo.

No main(), peça para o usuário inserir largura e altura, crie um retângulo e exiba sua área e perímetro.*/

#include <stdio.h>

typedef struct {
    float largura;
    float altura;
} Retangulo;

Retangulo criarRetangulo(float largura, float altura) { //funçao do tipo retangulo ??
    Retangulo r;
    r.largura = largura;
    r.altura = altura;
    return r; 
}

float calcularArea(Retangulo r) {
    return r.largura * r.altura;
}

float calcularPerimetro(Retangulo r) {
    return 2 * (r.largura + r.altura);
}

int main() {
    float largura, altura;

    printf("Digite a largura do retângulo em cm: ");
        scanf("%f", &largura);

    printf("Digite a altura do retângulo em cm: ");
        scanf("%f", &altura);

    Retangulo meuRetangulo = criarRetangulo(largura, altura);

    printf("\nÁrea: %.2fcm\n", calcularArea(meuRetangulo));
    printf("Perímetro: %.2fcm\n", calcularPerimetro(meuRetangulo));

    return 0;
}
