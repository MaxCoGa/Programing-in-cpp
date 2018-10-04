#include <cstddef>
#include <iostream>

using namespace std ;

void fillArray(int a[], int size);
int search(int *a, int size, int target);

int main( )
{
    int arraySize;
    cout << "How many numbers will be on the list? ";
    cin >> arraySize;

    int* a;
    a = new int[arraySize];

    fillArray(a, arraySize);

    int target;
    cout << "Enter a value to search for: ";
    cin >> target;
    int location = search(a, arraySize, target);
    if (location == -1)
        cout << target << " is not in the array.\n";
    else
        cout << target << " is element " << location << " in the array.\n";

    delete [] a;

    return 0;
}

void fillArray(int a[], int size)  // or int* a
{
    //cout << "Enter " << size << " integers.\n";
    for (int index = 0; index < size; index++)
        //cin >> a[index];
        a[index] = index * index;
}

int search(int *a, int size, int target) // or int a[]
{
    int index = 0;
    while ((a[index] != target) && (index < size))
        index++;
    if (index == size)//if target is not in a.
        index = -1;
    return index;
}

