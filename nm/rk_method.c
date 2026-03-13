#include <stdio.h>

float f(float x, float y)
{
    return x*y + 1;   // Example: dy/dx = x*y + 1
}

int main()
{
    float x0, y0, x, y, h, x_end;
    float k1, k2, k3, k4;

    printf("Enter initial value x0: ");
    scanf("%f", &x0);

    printf("Enter initial value y0: ");
    scanf("%f", &y0);

    printf("Enter final value of x: ");
    scanf("%f", &x_end);

    printf("Enter step size h: ");
    scanf("%f", &h);

    x = x0;
    y = y0;

    printf("x\t\ty\n");
    printf("%f\t%f\n", x, y);

    while(x < x_end)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x + h;

        printf("%f\t%f\n", x, y);
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}