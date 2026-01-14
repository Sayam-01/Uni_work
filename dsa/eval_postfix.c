#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int tos = -1;
void push(int x);
int pop();

int main(){
    char postfix[100], ch;
    int value[MAX];
    printf("Enter a valid postfix: ");
    scanf("%99s[^\n]", postfix);

    int length = strlen(postfix);
    for(int i = 0; i < length; i++){
        if(isalpha(postfix[i])){
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%i", &value[i]);
            push(value[i]);
        }
        else{
            ch = postfix[i];
            int op2 = pop();
            int op1 = pop();
            switch (ch){
                case '+':
                    push(op1+op2);
                    break;
                case '-':
                    push(op1-op2);
                    break;
                case '*':
                    push(op1*op2);
                    break;
                case '/':
                    push(op1/op2);
                    break;
                case '$' || '^':
                    push(pow(op1, op2));
                    break;
                case '%':
                    push(op1%op2);
                    break;
            }
        }
    }

    int result = pop();
    printf("The reuslt is: %i\n", result);

    printf("\n----By Sayam Shrestha-----\n");

    return 0;
}

void push(int x){
    stack[++tos] = x;
}

int pop(){
    int res = stack[tos--];
    return res;
}