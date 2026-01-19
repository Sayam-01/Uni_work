#include <stdio.h>

int main() {
    int totalMemory;
    int choice;

    printf("Enter total memory size: ");
    scanf("%d", &totalMemory);

    printf("\n1. MVT (Variable Partition)\n");
    printf("2. MFT (Fixed Partition)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int n, processSize[20];
        int usedMemory = 0;

        printf("\nEnter number of processes: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            printf("Enter memory required for Process %d: ", i + 1);
            scanf("%d", &processSize[i]);

            if (processSize[i] <= (totalMemory - usedMemory)) {
                printf("Process %d allocated\n", i + 1);
                usedMemory += processSize[i];
            } else {
                printf("Process %d cannot be allocated\n", i + 1);
            }
        }

        printf("\nTotal Memory: %d", totalMemory);
        printf("\nUsed Memory: %d", usedMemory);
        printf("\nRemaining Memory: %d\n", totalMemory - usedMemory);
    }

    else if (choice == 2) {
        int blockSize, n, processSize[20];
        int internalFragmentation = 0;

        printf("\nEnter block size: ");
        scanf("%d", &blockSize);

        int blocks = totalMemory / blockSize;

        printf("Total number of blocks: %d\n", blocks);

        printf("Enter number of processes: ");
        scanf("%d", &n);

        for (int i = 0; i < n && i < blocks; i++) {
            printf("Enter memory required for Process %d: ", i + 1);
            scanf("%d", &processSize[i]);

            if (processSize[i] <= blockSize) {
                internalFragmentation += blockSize - processSize[i];
                printf("Process %d allocated\n", i + 1);
            } else {
                printf("Process %d cannot be allocated\n", i + 1);
            }
        }

        printf("\nTotal Internal Fragmentation: %d\n", internalFragmentation);
    }

    else {
        printf("Invalid choice\n");
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
