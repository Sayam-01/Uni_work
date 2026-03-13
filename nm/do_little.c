#include <stdio.h>

int main()
{
    int n, i, j, k;
    float a[10][10], L[10][10], U[10][10], sum;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    // Initialize L and U
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j) L[i][j] = 1;
            else L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Doolittle Decomposition
    for(i = 0; i < n; i++)
    {
        // Upper Triangular
        for(j = i; j < n; j++)
        {
            sum = 0;
            for(k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];
            U[i][j] = a[i][j] - sum;
        }

        // Lower Triangular
        for(j = i+1; j < n; j++)
        {
            sum = 0;
            for(k = 0; k < i; k++)
                sum += L[j][k] * U[k][i];
            L[j][i] = (a[j][i] - sum) / U[i][i];
        }
    }

    printf("Lower Triangular Matrix L:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%8.4f ", L[i][j]);
        printf("\n");
    }

    printf("Upper Triangular Matrix U:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%8.4f ", U[i][j]);
        printf("\n");
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}