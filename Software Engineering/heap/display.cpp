//
// Created by devansh on 11/2/19.
//
#include <iostream>

using namespace std;

void display(int* array, int n)
{
    int i;
    if (n == 0)
    {
        cout << "Heap is empty \n";
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
