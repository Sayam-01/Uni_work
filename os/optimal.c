#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k;
    int pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        int found = 0;

        /* Check if page already in frame */
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        /* Page fault */
        if (!found) {
            int pos = -1, farthest = i + 1;

            for (j = 0; j < f; j++) {
                int nextUse = -1;

                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }

                if (nextUse == -1) {
                    pos = j;
                    break;
                }

                if (nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }

            if (pos == -1)
                pos = 0;

            frames[pos] = pages[i];
            pageFaults++;
        }

        printf("Frames: ");
        for (k = 0; k < f; k++)
            printf("%d ", frames[k]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
