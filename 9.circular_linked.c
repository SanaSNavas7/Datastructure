#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void search();
void display();

int main() {
    while (1) {
        int choice;
        printf("Enter choice:\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Search\n8. Display\n9. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertbeg(); break;
            case 2: insertend(); break;
            case 3: insertpos(); break;
            case 4: deletebeg(); break;
            case 5: deleteend(); break;
            case 6: deletepos(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0); break;
            default: printf("Invalid choice\n"); break;
        }
    }
}

void insertbeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = tail = newnode;
        newnode->next = head;
    } else {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
}

void insertend() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = tail = newnode;
        newnode->next = head;
    } else {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void insertpos() {
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        insertbeg();
    } else {
        struct node *temp = head;
        for (i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;

        if (temp == tail) { // If inserted at the last position
            tail = newnode;
        }
    }
}

void deletebeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    free(temp);
}

void deleteend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
}

void deletepos() {
    struct node *temp = head;
    int i,pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) { // Empty list
        printf("List is empty\n");
        return;
    }

    if (pos == 1) { // Deleting the first node
        deletebeg();
        return;
    }

    // Traverse to the node before the position
    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // Check if position is valid
    if (temp->next == head) {
        printf("Invalid position\n");
        return;
    }

    struct node *del = temp->next; // Node to be deleted
    temp->next = del->next;        // Skip the node to be deleted

    if (del == tail) { // If the deleted node is the tail
        tail = temp;
    }

    free(del); // Free the memory of the deleted node
    printf("Node deleted at position %d\n", pos);
}


void search() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int key, flag = 0;
    printf("Enter data to search: ");
    scanf("%d", &key);

    struct node *temp = head;
    do {
        if (temp->data == key) {
            flag = 1;
            printf("Data found\n");
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!flag) {
        printf("Data not found\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
