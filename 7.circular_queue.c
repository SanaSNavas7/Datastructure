#include<stdio.h>

int main()

{

int i,front=0,rear=0,ch,a[20],n,x=0,item,temp;

printf("\nEnter the limit for queue");

scanf("%d",&n);

do{

printf("\nEnter the choice");

printf("\n1. Insertion \t2. Deletion \t3. Display \t4.Exit");

scanf("%d",&ch);

switch(ch)

{

case 1:if(rear<n)

 {

 printf("enter the element");

 scanf("%d",&item);

 a[rear]=item;

 rear++;

 break;

 }

 else if(x<front && front!=0)

 {

 printf("enter the elements");

 scanf("%d",&item);

 a[x]=item;

 x++;

 break;

 }

 else

 printf("Circular queue full");

 break;

case 2:if(front!=n)

 front++;

 else

 printf("Queue is empty");

 break;

case 3:if(front==0)

 {for(i=front;i<rear;i++) 

 printf("%d\t",a[i]);}

 else

 {

 for(i=0;i<n;i++)

 printf("%d\t",a[i]);}

 break;
case 4:printf("\nExiting");

 break;

default:printf("\nWrong choice");

}

}while(ch!=4);

return 0;

}