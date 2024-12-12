
#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void peek();
void display();


struct node {
    int data;
    struct node *next;
};

struct node *top = NULL; 
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: // Pop
                pop();
                break;
            case 3: // Peek
                peek();
                break;
            case 4: // Display
                display();
                break;
            case 5: // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void push(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("%d pushed to stack\n", x);
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void pop() {
    struct node *temp=top;
    if (top == NULL) {
        printf("No elements to pop\n");
    }
   
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}
