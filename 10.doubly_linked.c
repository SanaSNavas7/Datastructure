#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void search();
void display();
int pos, i;
struct node *head = NULL;
struct node *newnode;
struct node *temp;
void main()
{

    while (1)
    {
        int choice;
        printf("enter 1.insertbeg \n  2.insertend \n 3.insertpos \n 4.deletebeg \n 5.deleteend \n 6.deletepos \n 7.search \n 8.display \n 9.exit\n");
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
            printf("invalid");
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
        head = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else
    {
        newnode->next = head;
        newnode->prev=NULL;
        head->prev = newnode;
        head=newnode;
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
        head = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
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
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deletebeg()
{
    temp=head;
    if (head == NULL)
    {
        printf("empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        head->next->prev = NULL;
        head = head->next;
    }
}

void deleteend()
{
    temp = head;
    if (head == NULL)
    {
        printf("empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);

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
    int flag = 0;
    temp = head;
    int a;
    printf("enter element to search: ");
    scanf("%d", &a);
    while (temp != NULL)
    {
        if (temp->data == a)
        {

            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("element not found");
    }
    else
    {
        printf("element found");
    }
}
    void display()
    {
        temp = head;
        if (head == NULL)
        {
            printf("empty");
        }
        else
        {
            for (temp = head; temp != NULL; temp = temp->next)
        {

            printf("%d->", temp->data);
        }
           
        }
    }
