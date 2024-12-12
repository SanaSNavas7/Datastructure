#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void display();

struct node{
int data;
struct node *next ;
};

struct node *front=NULL;
struct node *rear=NULL;

int main(){
while(1){
int choice;
printf("enter \n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:exit(0);
default:
printf("invalid entry");
}}
return 0;
}
void enqueue()
{
int d;
struct node *newnode = (struct node *)malloc(sizeof(struct node));
printf("Enter a value: ");
scanf("%d",&d);
newnode->data=d;
newnode->next=NULL;
if(front==NULL && rear==NULL)
{
front=rear=newnode;

}
else{

rear->next=newnode;
rear=newnode;

}}

 void dequeue()
{
struct node *temp=front;
if(front==NULL && rear==NULL){
printf("underflow");
}
else if(front==rear)
{
front=rear=NULL;
}
else{
printf("element  deleted is  %d\n",front->data);
front=temp;
front=front->next;
}}
void display()
{
struct node *temp=front;
while(temp!=NULL)
{
printf("%d->",temp->data );
temp=temp->next;
}}