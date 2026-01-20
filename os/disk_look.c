#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, direction;
    int request[50], up[50], down[50];
    int up_count = 0, down_count = 0;
    int i, total = 0, curr;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter initial direction (0=down, 1=up): ");
    scanf("%d", &direction);

    // Divide requests into up (>= head) and down (< head)
    for(i = 0; i < n; i++) {
        if(request[i] >= head) up[up_count++] = request[i];
        else down[down_count++] = request[i];
    }

    // Sort up ascending
    for(i = 0; i < up_count - 1; i++)
        for(int j = i+1; j < up_count; j++)
            if(up[i] > up[j]) { int t = up[i]; up[i] = up[j]; up[j] = t; }

    // Sort down descending
    for(i = 0; i < down_count - 1; i++)
        for(int j = i+1; j < down_count; j++)
            if(down[i] < down[j]) { int t = down[i]; down[i] = down[j]; down[j] = t; }

    printf("\nLOOK Disk Scheduling Order:\n");
    printf("%d", head);
    curr = head;

    if(direction == 1) { // moving up
        for(i = 0; i < up_count; i++) {
            printf(" -> %d", up[i]);
            total += abs(curr - up[i]);
            curr = up[i];
        }
        for(i = 0; i < down_count; i++) {
            printf(" -> %d", down[i]);
            total += abs(curr - down[i]);
            curr = down[i];
        }
    } else { // moving down
        for(i = 0; i < down_count; i++) {
            printf(" -> %d", down[i]);
            total += abs(curr - down[i]);
            curr = down[i];
        }
        for(i = 0; i < up_count; i++) {
            printf(" -> %d", up[i]);
            total += abs(curr - up[i]);
            curr = up[i];
        }
    }

    printf("\n\nTotal Head Movement = %d\n", total);
    printf("\n----By Sayam Shrestha----\n");

    return 0;
}
