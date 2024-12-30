#include <stdio.h>
#include <stdlib.h>
void insert();
void delete();
void display();
void search();
void insertbeg();
void insertend();
void deletebeg();
void deleteend();

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp, *new, *prev = NULL;

void main()
{
    int ch;
    while (1)
    {
        printf("\nSelect your operation\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
            break;
        }
    }
}

void insertbeg()
{
    if (head != NULL)
    {
        new->next = head;
        for (temp = head; temp->next != head; temp = temp->next)
        {
        }
        temp->next = new;
        head = new;
    }
    else
    {
        head = new;
        new->next = new;
    }
}
void insertend(){
    if (head == NULL)
        {
            head = new;
            new->next = head;
        }
        else
        {
            temp = head;
            for (temp = head; temp->next != head; temp = temp->next)
            {
            }
            temp->next = new;
            new->next = head;
        }
}

void insert()
{
    int ch, pos, count = 0;
    printf("enter the position\n1.insert at beginning\n2.insert at end\n3.insert at anywhere\n");
    scanf("%d", &ch);
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &new->data);
    switch (ch)
    {
    case 1:
        insertbeg();
        break;
    case 2:
        insertend();
        break;
    case 3:
        printf("Enter the position: ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            insertbeg();
            return;
        }
        temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        count++;
        if (pos < 1)
        {
            printf("Out of range!!");
            return;
        }
        if (pos > count + 1)
        {
            temp = head;
            for (temp = head; temp->next != head; temp = temp->next)
            {
            }
            temp->next = new;
            new->next = head;
            return;
        }
        if (pos == count + 1)
        {
            insertend();
            return;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        for (temp = head; temp->next != head; temp = temp->next)
        {
            printf("%d\t", temp->data);
        }
        printf("%d\t", temp->data);
    }
}
 
void deletebeg(){
    if (head == NULL)
        {
            printf("List is empty");
        }
        else if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;
            for (temp = head; temp->next != head; temp = temp->next)
            {
            }
            temp->next = head->next;
            head = head->next;
        }
}
void deleteend(){
    if (head == NULL)
        {
            printf("List is empty");
        }
        else if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;
            for (temp = head; temp->next != head; temp = temp->next)
            {
                prev = temp;
            }
            prev->next = head;
            free(temp);
        }
}
void delete()
{
    int ch, pos, count = 0;
    printf("enter the position\n1.delete from beginning\n2.delete from end\n3.delete from anywhere\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        deletebeg();
        break;
    case 2:
        deleteend();
        break;
    case 3:
        printf("enter the position of element to delete: ");
        scanf("%d", &pos);
        temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        count++;
        if (pos == 1)
        {
            deletebeg();
            return;
        }
        if (pos == count)
        {
            deleteend();
            return;
        }
        if(pos>count){
            printf("out of range!!");
            return;
        }
        else{
            temp=head;
            for(int i=1;i<pos;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            free(temp);
        }
        break;
    }
}

void search()
{
    int n, flag = 0;
    printf("Enter the element to search: ");
    scanf("%d", &n);
    temp = head;
    for (temp = head; temp->next != head; temp = temp->next)
    {
        if (temp->data == n)
        {
            flag = 1;
        }
    }
    if (temp->data == n)
    {
        flag = 1;
    }
    if (flag == 1)
    {
        printf("element found.\n");
    }
    else
    {
        printf("element not found.\n");
    }
    return;
}
