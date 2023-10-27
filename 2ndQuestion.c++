#include<iostream>
using namespace std;

//Abstract Data Type
class Stack {
    private:
        int maxSize;
        int *stackArray;
        int top;
    public:
        Stack(int);
        void push(int);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
};

//Implementation of ADT
Stack::Stack(int size) {
    maxSize = size;
    stackArray = new int[maxSize];
    top = -1;
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack is full." << endl;
    } else {
        stackArray[++top] = value;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return 0;
    } else {
        return stackArray[top--];
    }
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return 0;
    } else {
        return stackArray[top];
    }
}

bool Stack::isEmpty() {
    return (top == -1);
}

bool Stack::isFull() {
    return (top == maxSize - 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    Stack largest(n);
    Stack smallest(n);

    largest.push(array[0]);
    smallest.push(array[0]);

    for (int i = 1; i < n; i++) {
        if (array[i] > largest.peek()) {
            largest.push(array[i]);
        } else if (array[i] < smallest.peek()) {
            smallest.push(array[i]);
        }
    }

    cout << "Largest element: " << largest.peek() << endl;
    cout << "Smallest element: " << smallest.peek() << endl;

    return 0;
}