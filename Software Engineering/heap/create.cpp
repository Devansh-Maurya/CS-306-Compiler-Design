#include <iostream>

using namespace std;

#include "functions.h"

void create(int* array, int arraySize, int maxSize) {

    if (arraySize > maxSize) {
        cout << "Invalid size values\n";
        exit(4);
    }

    if (arraySize == 0)
        return;

    int *newArray = new int[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        insert(newArray, array[i], i);
    }

    for (int j = 0; j < arraySize; ++j) {
        array[j] = newArray[j];
    }

    delete [] newArray;
}