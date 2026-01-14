//stack operations in C
#include <stdio.h>
#define MAX 1000

int stack[MAX];
int n, top = -1, choice = 0;

void push();
void pop();
void display();

int main(){
    printf("Enter the number of elements in stack: ");
    scanf("%d", &n);
    if(n > MAX){
        printf("Stack size exceeded!\n");
        return 1;
    }
    stack[n];

    printf("----STACK OPERATIONS USING ARRAY----");
    printf("\n-----------------------------------\n");

    while(choice != 4){
        printf("Choose an opertaion:\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%i", &choice);

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("EXITING STACK OPERATIONS!\n");
                break;
            default:
                printf("Enter a valid opertaion: ");
        }
    }

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}

void push(){
    int value;
    if(top == n){
        printf("Stack is full. (stack overflow)\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%i", &value);
    top += 1;
    stack[top] = value;
}

void pop(){
    if(top == -1){
        printf("Stack is empty. (stack underflow)\n");
        return;
    }
    top -= 1;
    printf("Stack top is popped!\n");
}

void display(){
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    for(int i = top; i>=0; i--){
        printf("%i\n", stack[i]);
    }
}
