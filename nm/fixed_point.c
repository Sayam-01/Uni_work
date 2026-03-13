#include <stdio.h>
#include <math.h>

float g(float x)
{
    return pow(x + 2, 1.0/3.0);   // Example: x^3 - x - 2 = 0 rewritten as x = (x+2)^(1/3)
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
        x1 = g(x0);
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