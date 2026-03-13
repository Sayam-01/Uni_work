#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x + log(x+2);   // Example function: f(x) = x^2 + ln(x+2)
}

int main()
{
    int i, n;
    float a, b, h, x, sum = 0, I;

    printf("Enter lower limit a and upper limit b: ");
    scanf("%f %f", &a, &b);

    printf("Enter number of subintervals n (multiple of 3): ");
    scanf("%d", &n);

    if(n % 3 != 0)
    {
        printf("Number of subintervals must be a multiple of 3.\n");
        return 0;
    }

    h = (b - a) / n;
    sum = f(a) + f(b);

    for(i = 1; i < n; i++)
    {
        x = a + i*h;
        if(i % 3 == 0)
            sum += 2*f(x);
        else
            sum += 3*f(x);
    }

    I = (3*h/8) * sum;

    printf("Approximate integral = %f\n", I);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}