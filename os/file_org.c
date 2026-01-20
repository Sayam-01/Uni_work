#include <stdio.h>
#include <string.h>

#define MAX 10

/* ---------- SINGLE LEVEL DIRECTORY ---------- */
void singleLevel() {
    char files[MAX][20];
    int n, i;

    printf("\nEnter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter file name %d: ", i + 1);
        scanf("%s", files[i]);
    }

    printf("\nFiles in Single Level Directory:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", files[i]);
}

/* ---------- TWO LEVEL DIRECTORY ---------- */
void twoLevel() {
    char users[MAX][20];
    char files[MAX][MAX][20];
    int fileCount[MAX];
    int u, i, j;

    printf("\nEnter number of users: ");
    scanf("%d", &u);

    for (i = 0; i < u; i++) {
        printf("\nEnter user name: ");
        scanf("%s", users[i]);

        printf("Enter number of files for %s: ", users[i]);
        scanf("%d", &fileCount[i]);

        for (j = 0; j < fileCount[i]; j++) {
            printf("Enter file %d: ", j + 1);
            scanf("%s", files[i][j]);
        }
    }

    printf("\nTwo Level Directory Structure:\n");
    for (i = 0; i < u; i++) {
        printf("User: %s\n", users[i]);
        for (j = 0; j < fileCount[i]; j++) {
            printf("  %s\n", files[i][j]);
        }
    }
}

/* ---------- HIERARCHICAL DIRECTORY ---------- */
void hierarchical() {
    char root[20];
    char subDir[MAX][20];
    char files[MAX][MAX][20];
    int subCount, fileCount[MAX];
    int i, j;

    printf("\nEnter root directory name: ");
    scanf("%s", root);

    printf("Enter number of sub-directories: ");
    scanf("%d", &subCount);

    for (i = 0; i < subCount; i++) {
        printf("\nEnter sub-directory name %d: ", i + 1);
        scanf("%s", subDir[i]);

        printf("Enter number of files in %s: ", subDir[i]);
        scanf("%d", &fileCount[i]);

        for (j = 0; j < fileCount[i]; j++) {
            printf("Enter file %d: ", j + 1);
            scanf("%s", files[i][j]);
        }
    }

    printf("\nHierarchical Directory Structure:\n");
    printf("%s/\n", root);

    for (i = 0; i < subCount; i++) {
        printf("|-- %s/\n", subDir[i]);
        for (j = 0; j < fileCount[i]; j++) {
            printf("    |-- %s\n", files[i][j]);
        }
    }
}

int main() {
    int choice;

    printf("File Organization Techniques\n");
    printf("1. Single Level Directory\n");
    printf("2. Two Level Directory\n");
    printf("3. Hierarchical Directory\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: singleLevel(); break;
        case 2: twoLevel(); break;
        case 3: hierarchical(); break;
        default: printf("Invalid choice\n");
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
