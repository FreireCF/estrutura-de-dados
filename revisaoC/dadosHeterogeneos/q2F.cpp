/*Crie um programa que utilize uma struct chamada Aluno, contendo os seguintes campos:

    Nome do aluno (máximo 50 caracteres)
    Idade (inteiro)
    Nota final (float)

O programa deve permitir cadastrar 3 alunos, armazenando-os em um array. Após o cadastro, exiba os dados de todos os alunos cadastrados */

#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

int main (){
    Student students[3];
    
    for(int i=0; i<3; i++){
        printf("Whats the student name? ");
            scanf("%s",students[i].name);

        printf("Whats the student age? ");
            scanf("%d",&students[i].age);

        printf("Whats the student grade? ");
            scanf("%f",&students[i].grade);
    }
    
    printf("Students list: \n");
    
    for (int i=0; i<3; i++){
        printf("\nName: %s",students[i].name); 
        printf("\nAge: %d",students[i].age);
        printf("\nGrade: %.2f\n",students[i].grade);   
    }
}