#include <iostream>
#include <cstdlib>

using namespace std;

#include "functions.h"

int main() {
    int choice, num, totalElements;
    int size = 0;

    cout << "Enter the max size: ";
    cin >> size;

    cout << "Enter initial number of elements to create the heap: ";
    cin >> totalElements;

    int *array = new int[size];

    for (int i = 0; i < totalElements; ++i) {
        cout << "Enter element " << i+1 << ": ";
        cin >> array[i];
    }

    if (totalElements > 0) {
        create(array, totalElements, size);
    }

    while(1)
    {
        cout << "1.Insert the element \n";
        cout << "2.Delete the element \n";
        cout << "3.Display all elements \n";
        cout << "4.Quit \n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the element to be inserted to the list : ";
                cin >> num;
                insert(array, num, totalElements);
                totalElements++;
                break;
            case 2:
                cout << "Enter the elements to be deleted from the list: ";
                cin >> num;
                deleteElement(array, num, totalElements);
                totalElements--;
                break;
            case 3:
                display(array, totalElements);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice \n";
        }
    }
}