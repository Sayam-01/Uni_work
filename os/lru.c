#include <stdio.h>

int main() {
    int n, frames;
    int pages[30], frame[10];
    int time[10];
    int pageFaults = 0;
    int counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                counter++;
                time[j] = counter;
                break;
            }
        }

        if (!found) {
            int lru = 0;
            for (int j = 1; j < frames; j++) {
                if (time[j] < time[lru])
                    lru = j;
            }

            counter++;
            frame[lru] = pages[i];
            time[lru] = counter;
            pageFaults++;
        }

        printf("Frames: ");
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
