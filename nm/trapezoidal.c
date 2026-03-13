#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x + 2*x + 1;   // Example: f(x) = x^2 + 2x + 1
}

int main()
{
    float a, b, h, sum = 0, x, I;
    int n, i;

    printf("Enter lower limit a and upper limit b: ");
    scanf("%f %f", &a, &b);

    printf("Enter number of subintervals n: ");
    scanf("%d", &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for(i = 1; i < n; i++)
    {
        x = a + i*h;
        sum += 2*f(x);
    }

    I = (h/2)*sum;

    printf("Approximate integral = %f\n", I);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}