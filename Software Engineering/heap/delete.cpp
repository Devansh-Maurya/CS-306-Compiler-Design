#include <iostream>
#include "functions.h"

using namespace std;

void deleteElement(int* array, int num, int n)
{
    int left, right, i, temp, parentNode;

    for (i = 0; i < num; i++) {
        if (num == array[i])
            break;
    }
    if (num != array[i])
    {
        cout << num << " not found in heap list\n";
        return;
    }
    array[i] = array[n - 1];
    n = n - 1;
    parentNode =(i - 1) / 2;
    if (array[i] > array[parentNode])
    {
        insert(array, array[i], i);
        return;
    }
    left = 2 * i + 1;
    right = 2 * i + 2;
    while (right < n)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && array[i])    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}