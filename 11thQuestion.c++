#include<iostream>
using namespace std;

// maximum size of stack
#define MAX 10

// Stack structure
struct Stack {
    int top;
    int a[MAX];
};

// Function to initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
bool push(struct Stack *s, int x) {
    if (isFull(s)) {
        cout << "Stack Overflow\n";
        return false;
    }
    s->a[++s->top] = x;
    return true;
}

// Function to pop an element from the stack
bool pop(struct Stack *s, int *x) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return false;
    }
    *x = s->a[s->top--];
    return true;
}

// Function to display the stack elements
void display(struct Stack *s) {
    int i;
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return;
    }
    for (i = 0; i <= s->top; i++) {
        cout << s->a[i] << " ";
    }
    cout << "\n";
}

int main() {
    struct Stack s;
    int temp, choice;

    initStack(&s);

    while (1) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to be pushed: ";
            cin >> temp;
            if (push(&s, temp)) {
                cout << "Element pushed successfully\n";
            }
            break;
        case 2:
            if (pop(&s, &temp)) {
                cout << "Popped element is: " << temp << "\n";
            }
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid choice\n";
        }
    }
    return 0;
}