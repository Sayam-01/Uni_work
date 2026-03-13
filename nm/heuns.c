#include <stdio.h>

float f(float x, float y)
{
    return x - y;   // Example: dy/dx = x - y
}

int main()
{
    float x0, y0, x, y, h, x_end, y_predict;

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
        y_predict = y + h * f(x, y);
        y = y + (h/2) * (f(x, y) + f(x + h, y_predict));
        x = x + h;
        printf("%f\t%f\n", x, y);
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}