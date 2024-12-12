#include<stdio.h>
void main(){
    int a[20],b[20],c[50],i,j,n,m,s;
    printf("Enter the number of elements in first array :");
    scanf("%d",&n);
    printf("Enter the elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number of elements in second array :");
    scanf("%d",&m);
    printf("Enter the elements :");
    for(j=0;j<m;j++){
        scanf("%d",&b[j]);
    }
    printf("The first array is :");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nThe second  array is :");
    for(j=0;j<m;j++){
        printf("%d ",b[j]);
    }
    s=n+m;
    for(i=0;i<n;i++){
        c[i]=a[i];
    }
    for(j=0;j<m;j++){
        c[n]=b[j];
        n++;
    }
    printf("\nThe merged array is : ");
    for(i=0;i<s;i++){
        printf("%d ",c[i]);
    }
}