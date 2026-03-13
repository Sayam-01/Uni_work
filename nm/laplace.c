#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, m, n, iter = 0;
    float u[10][10], u_old[10][10], tol, max_diff;

    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("Enter tolerance: ");
    scanf("%f", &tol);

    // Initialize grid with 0
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            u[i][j] = 0;

    // Input boundary conditions
    printf("Enter top boundary values (left to right):\n");
    for(j = 0; j < n; j++)
        scanf("%f", &u[0][j]);

    printf("Enter bottom boundary values (left to right):\n");
    for(j = 0; j < n; j++)
        scanf("%f", &u[m-1][j]);

    printf("Enter left boundary values (top to bottom, excluding corners):\n");
    for(i = 1; i < m-1; i++)
        scanf("%f", &u[i][0]);

    printf("Enter right boundary values (top to bottom, excluding corners):\n");
    for(i = 1; i < m-1; i++)
        scanf("%f", &u[i][n-1]);

    // Iterative solution using finite difference
    do
    {
        iter++;
        max_diff = 0;

        // Copy current values to u_old
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                u_old[i][j] = u[i][j];

        // Update interior points
        for(i = 1; i < m-1; i++)
        {
            for(j = 1; j < n-1; j++)
            {
                u[i][j] = 0.25 * (u_old[i+1][j] + u_old[i-1][j] + u_old[i][j+1] + u_old[i][j-1]);
                if(fabs(u[i][j] - u_old[i][j]) > max_diff)
                    max_diff = fabs(u[i][j] - u_old[i][j]);
            }
        }

    } while(max_diff > tol);

    // Display final solution
    printf("\nSolution after %d iterations:\n", iter);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%8.4f ", u[i][j]);
        printf("\n");
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}