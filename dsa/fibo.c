#include <stdio.h>

int fibo(int n){
    if(n <= 1 ) return n;

    return fibo(n-1) + fibo(n - 2);
}


int main(){
    int x;
    printf("Please enter the number: ");
    scanf("%i",&x);

    printf("The fibonacci sequence for %i terms are: ", x);
    for(int i = 0; i < x; i++){
        printf("%i ", fibo(i));
    }

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}   