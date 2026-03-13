#include <stdio.h>

int main()
{
    int i, n, index = -1;
    float x[20], y[20], h, x0, derivative;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the point x0 where derivative is required: ");
    scanf("%f", &x0);

    // Find index of x0
    for(i = 0; i < n; i++)
    {
        if(x[i] == x0)
        {
            index = i;
            break;
        }
    }

    if(index == -1 || index == n-1)
    {
        printf("Cannot apply forward difference at this point.\n");
        return 0;
    }

    h = x[index+1] - x[index];
    derivative = (y[index+1] - y[index]) / h;

    printf("Derivative at x = %f is %f\n", x0, derivative);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}