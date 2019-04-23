#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct page {
    int pageVal;
    int useCount;
};

typedef struct page page;

void lruPageReplacement(int totalSlots, int totalPages, page *pages);
int isPageInMemory(int, int, const page*);

int main() {

    int n, slots;
    page *pages;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    pages = (page*) malloc(sizeof(page)*n);

    printf("Enter the pages: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &(pages[i].pageVal));
    }
    getchar();

    printf("Enter the slots: ");
    scanf("%d", &slots);

    lruPageReplacement(slots, n, pages);

    free(pages);

    return 0;
}

void lruPageReplacement(int totalSlots, int totalPages, page *pages) {

    int slotPtr = 0, pageFaults = 0;
    page *slots;

    slots = (page*) malloc(sizeof(page)*totalSlots);

    for (int i = 0; i < totalSlots; ++i) {
        slots[i].pageVal = -1;
    }

    for (int i = 0; i < totalPages; ++i) {
        pages[i].useCount = 0;
    }

    for (int j = 0; j < totalPages; ++j) {

        for (int i = 0; i < totalSlots; ++i) {
            if (slots[i].pageVal != -1)
                slots[i].useCount++;
        }

        if (!isPageInMemory(pages[j].pageVal, totalSlots, slots)) {

            printf("Miss!\t:\t");
            pageFaults++;

            if (slotPtr < totalSlots) {
                slots[slotPtr].pageVal = pages[j].pageVal;
                slots[slotPtr].useCount = 0;
                slotPtr++;
            } else {

                int lru = 0;
                for (int i = 0; i < totalSlots; ++i) {
                    if (slots[i].useCount >= slots[lru].useCount) {
                        lru = i;
                    }
                }

                slots[lru].pageVal = pages[j].pageVal;
                slots[lru].useCount = 0;

            }
        } else {

            for (int i = 0; i < totalSlots; ++i) {
                if (slots[i].pageVal == pages[j].pageVal)
                    slots[i].useCount = 0;
            }

            printf("Hit!\t:\t");
        }

        for (int l = 0; l < totalSlots; ++l) {
            if (slots[l].pageVal != -1)
                printf("%d ", slots[l].pageVal);
        }
        printf("\n");
    }

    printf("\nPage Faults: %d", pageFaults);

}

int isPageInMemory(int page, int slotsNum, const struct page *slots) {
    for (int i = 0; i < slotsNum; ++i) {
        if (slots[i].pageVal == page)
            return 1;
    }
    return 0;
}