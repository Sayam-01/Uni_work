#include <stdio.h>

#define MAX 50

/* ---------- SEQUENTIAL ALLOCATION ---------- */
void sequential() {
    int start, length, i;

    printf("\nEnter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file: ");
    scanf("%d", &length);

    printf("\nSequential Allocation:\n");
    for (i = 0; i < length; i++) {
        printf("Block %d allocated\n", start + i);
    }
}

/* ---------- INDEXED ALLOCATION ---------- */
void indexed() {
    int indexBlock, n, blocks[MAX], i;

    printf("\nEnter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndexed Allocation:\n");
    printf("Index Block %d contains:\n", indexBlock);
    for (i = 0; i < n; i++) {
        printf("  Block %d\n", blocks[i]);
    }
}

/* ---------- LINKED ALLOCATION ---------- */
void linked() {
    int n, blocks[MAX], i;

    printf("\nEnter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nLinked Allocation:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d -> ", blocks[i]);
    }
    printf("%d\n", blocks[n - 1]);
}

int main() {
    int choice;

    printf("File Allocation Strategies\n");
    printf("1. Sequential Allocation\n");
    printf("2. Indexed Allocation\n");
    printf("3. Linked Allocation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: sequential(); break;
        case 2: indexed(); break;
        case 3: linked(); break;
        default: printf("Invalid choice\n");
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
