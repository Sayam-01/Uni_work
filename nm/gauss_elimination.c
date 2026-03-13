#include <stdio.h>

int main()
{
    int i, j, k, n;
    float a[10][10], b[10], x[10], factor, sum;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients of the system and constants:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
        scanf("%f", &b[i]);
    }

    // Forward Elimination
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            factor = a[j][i] / a[i][i];
            for(k = i; k < n; k++)
                a[j][k] -= factor * a[i][k];
            b[j] -= factor * b[i];
        }
    }

    // Back Substitution
    for(i = n-1; i >= 0; i--)
    {
        sum = b[i];
        for(j = i+1; j < n; j++)
            sum -= a[i][j] * x[j];
        x[i] = sum / a[i][i];
    }

    printf("Solution:\n");
    for(i = 0; i < n; i++)
        printf("x%d = %f\n", i+1, x[i]);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}