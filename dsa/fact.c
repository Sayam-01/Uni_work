#include <stdio.h>

int fact(int n){
    if(n<=1) return 1;

    return n * fact(n-1);
}

int main(){
    int x;
    printf("Please enter the number: ");
    scanf("%i",&x);

    int result = fact(x);
    printf("The factorial of %i is: %i", x, result);

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}   