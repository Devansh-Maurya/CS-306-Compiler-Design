#include <stdio.h>

#define SLOTS 3
#define TRUE 1
#define FALSE 0

typedef int bool;

int pageQueue[SLOTS];

bool isPageInMemory(int page) {
    for (int i = 0; i < SLOTS; ++i) {
        if (pageQueue[i] == page)
            return TRUE;
    }
    return FALSE;
}

int main() {

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    int currentPos = 0;
    int n = sizeof(pages)/ sizeof(int);
    int pageFaults = 0;

    for (int i = 0; i < SLOTS; ++i) {
        pageQueue[i] = -1;
    }

    for (int j = 0; j < n; ++j) {
        printf("\nQueue before adding page:");
        for (int i = 0; i < SLOTS; ++i) {
            printf(" %d", pageQueue[i]);
        }

        if (!isPageInMemory(pages[j])) {
            pageQueue[currentPos] = pages[j];
            currentPos = (currentPos + 1)%SLOTS;
            pageFaults++;

            printf("\nQueue after adding page:");
            for (int i = 0; i < SLOTS; ++i) {
                printf(" %d", pageQueue[i]);
            }
        }
    }

    printf("\nPage faults: %d", pageFaults);

    return 0;
}