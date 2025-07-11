#include <stdio.h>

void inserirCpf(int *cpf) {
    printf("Digite o CPF do funcionário (0 para sair): ");
    scanf("%d", cpf);
}

int inserirFaltas() {
    int faltas;
    printf("Digite a quantidade de faltas do funcionário: ");
    scanf("%d", &faltas);
    return faltas;
}

void maisFaltas(int cpf, int faltas, int *cpfMaisFaltas, int *maxFaltas) {
    if (faltas > *maxFaltas) {
        *maxFaltas = faltas;
        *cpfMaisFaltas = cpf;
    }
}

int main() {
    int cpf, faltas, cpfMaisFaltas = 0, maxFaltas = -1;
    int totalFaltas = 0, totalFuncionarios = 0;

    do {
        inserirCpf(&cpf);
        if (cpf == 0) {
            break;
        }

        faltas = inserirFaltas();
        maisFaltas(cpf, faltas, &cpfMaisFaltas, &maxFaltas);

        totalFaltas += faltas;
        totalFuncionarios++;
    } while (cpf != 0);

    if (totalFuncionarios > 0) {
        float mediaFaltas = totalFaltas / totalFuncionarios;
        printf("O CPF com mais faltas foi: %d\n", cpfMaisFaltas);
        printf("A média de faltas foi: %.2f\n", mediaFaltas);
    } else {
        printf("Nenhum funcionário foi inserido.\n");
    }
}