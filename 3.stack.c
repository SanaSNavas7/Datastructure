#define SIZE 5
int stack[SIZE],size,i,top=-1;
#include <stdio.h>
#include<stdlib.h>
void push(int stack[]);
void pop(int stack[]);
void peek(int stack[]);
void display(int stack[]);

int main()
{
printf("enter size of stack: ");
scanf("%d",&size);
if(size>SIZE)
{
printf("Size is larger");
}
else
{
printf("enter elements of stack: ");
for(i=0;i<size;i++)
{
scanf("%d",&stack[i]);
top++;
}
}


while(1)
{
int ch;
printf("enter \n 1.push\n 2.pop\n 3.peek\n 4.display\n 5.exit ");

scanf("%d",&ch);
switch(ch){
case 1:push(stack);
break;
case 2:pop(stack);
break;
case 3:peek(stack);
break;
case 4:display(stack);
break;
case 5:exit(0);
break;
default:printf("invalid");
}}return 0;
}



void push(int stack[])
{
int ele;
if(top>=SIZE)
{
printf("overflow");
}
else
{
printf("enter element to insert");
scanf("%d",&ele);
top=top+1;
stack[top]=ele;
}
}

void pop(int stack[])
{
int d;
if(top==-1)
{
printf("underflow");
}
else
{
d=stack[top];
top--;
}
}

void  peek(int stack[])
{
if(top==-1)
{
printf("underflow");
}
else
{
printf("top element is %d",stack[top]);
}
}

void display(int stack[])
{
if(top==-1)
{
printf("underflow");
}
else
{
for(i=0;i<=top;i++)
{
printf("%d",stack[i]);
}

}
}






