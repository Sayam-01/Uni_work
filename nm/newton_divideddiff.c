#include <stdio.h>

int main()
{
    int i, j, n;
    float x[20], y[20][20], xp, yp, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i][0]);
    }

    for(j = 1; j < n; j++)
    {
        for(i = 0; i < n - j; i++)
        {
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xp);

    yp = y[0][0];
    term = 1;

    for(i = 1; i < n; i++)
    {
        term = term * (xp - x[i-1]);
        yp = yp + term * y[0][i];
    }

    printf("Interpolated value at x = %f is y = %f\n", xp, yp);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}