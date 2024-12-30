#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 100
int s[SIZE], i, size;
int top = -1;

void push();
void pop();
void peek();
void display();

int main()
{
    printf("enter size of stack");
    printf("\n");
    scanf("%d", &size);

    while (1)
    {
        int choice;
        printf("enter 1.push \n 2.pop \n 3.peek \n 4.display \n 5.exit");
        printf("\n");
        scanf("%d", &choice);
        switch (choice)
        {
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
            break;
        default:
            printf("invalid");
        }
    }
    return 0;
}

void push()
{
    int item;
    printf("enter element to insert");
    printf("\n");
    scanf("%d", &item);
    if (top == SIZE - 1)
    {
        printf("overflow");
        printf("\n");
    }
    else
    {
        top = top + 1;
        s[top] = item;
    }
}

void pop()
{
    int a;
    if (top == -1)
    {
        printf("Underflow");
        printf("\n");
    }
    else
    {
        a = s[top];
    }
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("stack empty");
        printf("\n");
    }
    else
    {
        printf("top element is %d", s[top]);
        printf("\n");
    }
}

void display()
{
    if (top == -1)
    {
        printf("underflow");
        printf("\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d ", s[i]);
            
        }
    }
}
