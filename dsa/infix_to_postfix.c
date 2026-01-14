#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

int isRightAssociative(char op) {
    return (op == '^');
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        /* If operand, add to postfix */
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        /* If '(', push */
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        /* If ')', pop until '(' */
        else if (infix[i] == ')') {
            while (top != -1 && (x = pop()) != '(') {
                postfix[k++] = x;
            }
            if (x != '(') {
                printf("Mismatched parentheses!\n");
                return 1;
            }
        }
        /* If operator */
        else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                if (isRightAssociative(infix[i])) {
                    // For right-associative operators, only pop if higher precedence
                    if (precedence(peek()) > precedence(infix[i])) {
                        postfix[k++] = pop();
                    } else {
                        break;
                    }
                } else {
                    // For left-associative operators, pop if precedence is equal or higher
                    postfix[k++] = pop();
                }
            }
            push(infix[i]);
        }
        i++;
    }

    /* Pop remaining operators */
    while (top != -1) {
        x = pop();
        if (x == '(') {
            printf("Mismatched parentheses!\n");
            return 1;
        }
        postfix[k++] = x;
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}