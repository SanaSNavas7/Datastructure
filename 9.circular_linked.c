#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *newnode;
struct node *temp;

void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void search();
void display();

int pos, i;

int main()
{
    while (1)
    {
        int choice;
        printf("Enter 1.insertbeg \n 2.insertend \n 3.insertpos \n 4.deletebeg \n 5.deleteend \n 6.deletepos \n 7.search \n 8.display \n 9.exit\n");
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
        case 4:
            deletebeg();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deletepos();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
void insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
}
void insertend()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        tail->next = newnode;
        tail->next = newnode;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        head = newnode;
        tail->next = newnode;
    }
}

void insertpos()
{
    temp = head;
    printf("enter pos: ");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        insertbeg();
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deletebeg()
{
    temp = head;
    if (head == NULL)
    {
        printf("list empty");
    }
    else if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }
}
void deleteend()
{
    temp = head;
    if (head == NULL)
    {
        printf("list empty");
    }
    else if (temp->next == tail)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = head;
    }
}
void deletepos()
{
    printf("enter pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletebeg();
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}
void search()
{
    temp = head;
    int a;
    printf("enter data");
    scanf("%d", &a);
    int flag = 0;
    do
    {
        if (temp->data == a)
        {
            flag = 1;
            printf("found");
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if(flag==0){
        printf("not found");
    }
}

void display()
{
    if (head == NULL)
    {
        printf("empty");
    }
    temp = head;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD");
}
