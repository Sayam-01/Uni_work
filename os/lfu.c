#include <stdio.h>

int main() {
    int pages[50], frames[10], freq[10], time[10];
    int n, f, i, j, k;
    int pageFaults = 0, t = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                freq[j]++;
                time[j] = ++t;
                found = 1;
                break;
            }
        }

        if (!found) {
            int minFreq = freq[0], pos = 0;

            for (j = 1; j < f; j++) {
                if (freq[j] < minFreq ||
                    (freq[j] == minFreq && time[j] < time[pos])) {
                    minFreq = freq[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            freq[pos] = 1;
            time[pos] = ++t;
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
