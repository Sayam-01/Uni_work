#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x*x - x - 2;   // Nonlinear equation
}

float df(float x)
{
    return 3*x*x - 1;       // Derivative of the function
}

int main()
{
    float x0, x1, e;
    int i = 0;

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    printf("Enter allowed error: ");
    scanf("%f", &e);

    do
    {
        x1 = x0 - (f(x0) / df(x0));
        i++;

        if (fabs(x1 - x0) < e)
            break;

        x0 = x1;

    } while (1);

    printf("Approximate root = %f\n", x1);
    printf("Number of iterations = %d\n", i);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}