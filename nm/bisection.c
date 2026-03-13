#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x*x - x - 2; //example non-linear function
}

int main()
{
    float a, b, c, e;
    int i = 0;

    printf("Enter initial guesses a and b: ");
    scanf("%f %f", &a, &b);

    printf("Enter allowed error: ");
    scanf("%f", &e);

    if (f(a) * f(b) >= 0)
    {
        printf("Invalid initial guesses.\n");
        return 0;
    }

    do
    {
        c = (a + b) / 2;
        i++;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) > e);

    printf("Approximate root = %f\n", c);
    printf("Number of iterations = %d\n", i);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}