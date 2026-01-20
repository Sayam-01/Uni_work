#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int request[50];
    int head, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    total += abs(head - request[0]);

    for (i = 1; i < n; i++) {
        total += abs(request[i] - request[i - 1]);
    }

    printf("\nFCFS Disk Scheduling Order:\n");
    printf("%d", head);
    for (i = 0; i < n; i++) {
        printf(" -> %d", request[i]);
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
