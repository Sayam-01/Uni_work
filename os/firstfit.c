#include <stdio.h>

int main() {
    int nb, np;
    int blockSize[20], processSize[20];
    int allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    // First-Fit Allocation
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Output
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
