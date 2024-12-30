#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void peek();
void display();

int main() {
    while (1) {
        int choice;
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void push() {
    int value;
    printf("\nEnter value to insert: ");
    scanf("%d", &value);
    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    
    printf("Element %d pushed onto the stack.\n", value);
}

void pop() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
    } else {
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty! No element to peek.\n");
    } else {
        printf("Peek element: %d\n", top->data);
    }
}

void display() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty! Nothing to display.\n");
    } else {
        printf("\nStack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
