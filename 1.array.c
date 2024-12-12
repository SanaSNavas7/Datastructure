int arr[30];
int n;
void insertion();
void deletion();
void search();
void display();
#include<stdio.h>
#include<stdlib.h>
void main()
{   
    int c,i;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    printf("\nEnter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    while(1){
    printf("\n***ARRAY OPERATIONS***\n");
    printf("1.DISPLAY\n");
    printf("2.INSERTION\n");
    printf("3.DELETION\n");
    printf("4.SEARCH\n");
    printf("5.EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
               display();
               break;
        case 2:
                insertion();
                break;
        case 3:
                deletion();
                break;
        case 4:
                search();
                break;
        case 5:
                exit(1);
                break;
        default :
                printf("Invalid option\n");
                break;
     } 
    }
}
void display()
{
    int i;
    printf("The array elements are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void insertion()
{
    int x,p;
    printf("\nEnter the position to insert : ");
    scanf("%d",&p);
    printf("Enter the data to be inserted : ");
    scanf("%d",&x);
    n=n+1;
    for(int i=n;i>=p-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[p-1]=x;
}
void deletion()
{
    int p,x;
    printf("\nEnter the position to delete :");
    scanf("%d",&p);
    x=arr[p-1];
    printf("The deleted element is : %d",x);
    n=n-1;
    for(int i=p-1;i<=n;i++)
    {
        arr[i]=arr[i+1];
    }
}
void search()
{
    int s,p,i,flag=0;
    printf("The element you are searching for :");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(s==arr[i])
        {
            printf("The element found at position %d",i+1);
            flag=1;
        }
    }
if(flag==0)
{
    printf("Element not found");
}
}