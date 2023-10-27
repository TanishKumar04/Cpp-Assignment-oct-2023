#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // allocate memory
    int* arr = new int[size];

    // read array elements
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // display array elements
    cout << "The elements of the array are: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    // deallocate memory
    delete[] arr;

    return 0;
}