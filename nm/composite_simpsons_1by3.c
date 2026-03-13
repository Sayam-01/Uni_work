#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*exp(x) + cos(x);   // Example function: f(x) = x*e^x + cos(x)
}

int main()
{
    int i, n;
    float a, b, h, x, sum = 0, I;

    printf("Enter lower limit a and upper limit b: ");
    scanf("%f %f", &a, &b);

    printf("Enter number of subintervals n (even): ");
    scanf("%d", &n);

    if(n % 2 != 0)
    {
        printf("Number of subintervals must be even.\n");
        return 0;
    }

    h = (b - a) / n;
    sum = f(a) + f(b);

    for(i = 1; i < n; i++)
    {
        x = a + i*h;
        if(i % 2 == 0)
            sum += 2*f(x);
        else
            sum += 4*f(x);
    }

    I = (h/3) * sum;

    printf("Approximate integral = %f\n", I);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}