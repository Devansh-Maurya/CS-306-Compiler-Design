#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void optimalPageReplacement(int totalSlots, int totalPages, int* pages);
int isPageInMemory(int, int, const int*);

int main() {

    int n, slots, *pages;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    pages = (int*) malloc(sizeof(int)*n);

    printf("Enter the pages: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    getchar();

    printf("Enter the slots: ");
    scanf("%d", &slots);

    optimalPageReplacement(slots, n, pages);

    free(pages);

    return 0;
}

void optimalPageReplacement(int totalSlots, int totalPages, int* pages) {

    int *slots, *useCount, slotPtr = 0, pageFaults = 0;

    slots = (int*) malloc(sizeof(int)*totalSlots);
    useCount = (int*) malloc(sizeof(int)*totalSlots);

    for (int i = 0; i < totalSlots; ++i) {
        slots[i] = -1;
    }

    for (int i = 0; i < totalPages; ++i) {
        useCount[i] = INT_MAX;
    }

    for (int j = 0; j < totalPages; ++j) {

        if (!isPageInMemory(pages[j], totalSlots, slots)) {

            printf("Miss!\t:\t");
            pageFaults++;

            if (slotPtr < totalSlots) {
                slots[slotPtr] = pages[j];
                slotPtr++;
            } else {

                for (int i = 0; i < totalPages; ++i) {
                    useCount[i] = INT_MAX;
                }

                for (int rPtr = j; rPtr < totalPages; ++rPtr) {
                    for (int i = 0; i < totalSlots; ++i) {
                        if (pages[rPtr] == slots[i]) {
                            if (useCount[i] == INT_MAX)
                                useCount[i] = rPtr;
                            break;
                        }
                    }
                }

                int max = 0;
                for (int k = 0; k < totalSlots; ++k) {
                    if (useCount[k] > useCount[max]) {
                        max = k;
                    }
                }

                slots[max] = pages[j];
            }
        } else {
            printf("Hit!\t:\t");
        }

        for (int l = 0; l < totalSlots; ++l) {
            printf("%d ", slots[l]);
        }
        printf("\n");
    }

    printf("\nPage Faults: %d", pageFaults);

}

int isPageInMemory(int page, int slotsNum, const int *slots) {
    for (int i = 0; i < slotsNum; ++i) {
        if (slots[i] == page)
            return 1;
    }
    return 0;
}