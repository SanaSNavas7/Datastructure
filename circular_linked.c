#include <stdio.h>
#include <stdlib.h>
void insertbeg();
void insertend();
void insertpos();
void display();

struct node
{
    int data;
    struct node *next, *tail;
};
struct node *temp, *newnode;
struct node *head = NULL;

int main()
{
    while (1)
    {
        int choice;
        printf("\n------Enter your choice-----\n1.Insert_Beginning\n2.Insert_End\n3.Insert_Position\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertbeg();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
            case 4: display();
            break;
            case 5:exit(0);
            break;

        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
void insertbeg()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    head->tail = head;
}

void insertend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert : ");
    scanf("%d", &newnode->data);
    temp = head;
    while ((temp->next->tail) != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->tail = head;
}

void insertpos()
{
    int pos, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the poition to insert: ");
    scanf("%d", &newnode->data);
    temp = head;
    if (pos == 1)
    {
        insertbeg();
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp->next = newnode;
            newnode->next = temp->next->next;
        }
    }
}

void display()
{
    temp=head;
    while(temp->next!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
        
    }
    
}