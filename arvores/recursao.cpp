#include <stdio.h>

int fatorial(int num){
    if(num==0){
        return 1;
    } else{
        return num*fatorial(num-1);
    }
}

int potencia(int base, int exp){
    if(exp==1){
        return base;
    } else {
        return base*potencia(base, exp-1);
    }

}

int main(){
    printf("%d",fatorial(4));
    printf("\n");

    printf("%d",potencia(2, 4));
    printf("\n");


}