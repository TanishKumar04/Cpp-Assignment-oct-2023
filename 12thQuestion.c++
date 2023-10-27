#include<iostream>
using namespace std;

#define MAX_SIZE 10

// Structure for Queue
struct Queue {
    int front;
    int rear;
    int arr[MAX_SIZE];
};

// Function to check if the queue is full
bool isFull(struct Queue *q) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        return true;
    }
    return false;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *q) {
    if (q->front == -1) {
        return true;
    }
    return false;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        cout << "Queue is full. Cannot add element: " << value << endl;
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = value;
    if (q->front == -1) {
        q->front = 0;
    }
    cout << "Element added to the queue: " << value << endl;
}

// Function to remove an element from the queue
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty. Cannot remove element.\n";
        return;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    cout << "Element removed from the queue: " << value << endl;
}

// Function to display the queue
void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty.\n";
        return;
    }
    int i = q->front;
    do {
        cout << q->arr[i] << " ";
        i = (i + 1) % MAX_SIZE;
    } while (i != q->rear);
    cout << endl;
}

// Driver function
int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    displayQueue(&q);

    dequeue(&q);
    dequeue(&q);

    displayQueue(&q);

    return 0;
}