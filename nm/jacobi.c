#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n, iter = 0;
    float a[10][10], b[10], x[10], x_new[10], tol, max_diff, sum;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients of the system and constants:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%f", &a[i][j]);
        scanf("%f", &b[i]);
    }

    printf("Enter initial guesses for variables:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter tolerance: ");
    scanf("%f", &tol);

    printf("\nIteration Table:\n");
    printf("Iter\t");
    for(i = 0; i < n; i++)
        printf("x%d\t\t", i+1);
    printf("\n");

    do
    {
        iter++;
        max_diff = 0;

        for(i = 0; i < n; i++)
        {
            sum = b[i];
            for(j = 0; j < n; j++)
            {
                if(j != i)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
            if(fabs(x_new[i] - x[i]) > max_diff)
                max_diff = fabs(x_new[i] - x[i]);
        }

        // Print current iteration values
        printf("%d\t", iter);
        for(i = 0; i < n; i++)
        {
            x[i] = x_new[i];  // Update values
            printf("%f\t", x[i]);
        }
        printf("\n");

    } while(max_diff > tol);

    printf("\nSolution after %d iterations:\n", iter);
    for(i = 0; i < n; i++)
        printf("x%d = %f\n", i+1, x[i]);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}