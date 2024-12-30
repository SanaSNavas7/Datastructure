#include<stdio.h>
#include<stdlib.h>

#define size 5

int q[size];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    if (rear == size - 1) {
        printf("\nOverflow\n");
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
        printf("\nUnderflow\n");
        return 1;
    }
    return 0;
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

// Function to add an element to the queue
void enqueue() {
    int ele;
    printf("\nEnter the element for insertion: ");
    scanf("%d", &ele);

    if (isFull()) {
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    rear++;
    q[rear] = ele;
    display();
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        return;
    }
    printf("\nDequeued element: %d\n", q[front]);
    front++;
    display();
}

void main() {
    while (1) {
        int ch;
        printf("\nEnter your choice: \n1. Enqueue \n2. Dequeue \n3. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
}
