#include <stdio.h>

int main()
{
    int i, j, k, n;
    float a[10][10], b[10], factor;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients of the system and constants:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%f", &a[i][j]);
        scanf("%f", &b[i]);
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++)
    {
        // Make pivot element 1
        factor = a[i][i];
        for(j = 0; j < n; j++)
            a[i][j] /= factor;
        b[i] /= factor;

        // Make other elements in column 0
        for(j = 0; j < n; j++)
        {
            if(j != i)
            {
                factor = a[j][i];
                for(k = 0; k < n; k++)
                    a[j][k] -= factor * a[i][k];
                b[j] -= factor * b[i];
            }
        }
    }

    printf("Solution:\n");
    for(i = 0; i < n; i++)
        printf("x%d = %f\n", i+1, b[i]);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}