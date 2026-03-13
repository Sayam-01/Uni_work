#include <stdio.h>

int main()
{
    int i, j, n;
    float x[20], y[20], xp, yp = 0, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xp);

    for(i = 0; i < n; i++)
    {
        term = y[i];

        for(j = 0; j < n; j++)
        {
            if(i != j)
            {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp = yp + term;
    }

    printf("Interpolated value at x = %f is y = %f\n", xp, yp);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}