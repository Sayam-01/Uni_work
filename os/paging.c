#include <stdio.h>

int main() {
    int pageSize, numPages;
    int pageTable[20];
    int pageNumber, offset;
    int frameNumber, physicalAddress;

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    printf("Enter frame number for each page:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter page number: ");
    scanf("%d", &pageNumber);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if (pageNumber >= numPages || offset >= pageSize) {
        printf("\nInvalid logical address\n");
    } else {
        frameNumber = pageTable[pageNumber];
        physicalAddress = (frameNumber * pageSize) + offset;

        printf("\nPage Number: %d", pageNumber);
        printf("\nFrame Number: %d", frameNumber);
        printf("\nPhysical Address: %d\n", physicalAddress);
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
