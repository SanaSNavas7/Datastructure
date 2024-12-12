#include<stdio.h>
#include<conio.h>

int uni[50],set1[50],set2[50], num, num1,num2, i, temp, exists, j=0, bitstringset1[50],bitstringset2[50],choice;
int unionarray[50], intersectionarray[50], differencearray[50];
void unionbitstr();
void intersection();

void main(){
    //PROMPT FOR THE UNIVERSAL SET
    printf("Enter the size of the universal set: ");
    scanf("%d",&num);
    //CHECK IF THE ELEMENT EXISTS; ENTER INTO THE SET IF IT DOESNT
    while(j<num){
        exists=0;
        printf("\nEnter the element for the universal set: \n");
        scanf("%d",&temp);
        for(i=0;i<num;i++){
            if(temp==uni[i]){
                printf("\nThe element already exists.");
                exists=1;
            }
        }
        if(exists==0){
            uni[j]=temp;
            j++;
        }
    }
    for(i=0;i<num;i++){
        printf("%d",uni[i]);
    }
//PROMPT FOR THE FIRST SET
    j=0;
    printf("\nEnter the size of the first set: ");
    scanf("%d",&num1);
    while(j<num1){
        exists=0;
        printf("\nEnter the element for the set: ");
        scanf("%d",&temp);
        for(i=0;i<num1;i++){
            if(temp==set1[i]){
                printf("\nThe element already exists.");
                exists=1;
            }
        }
        if(exists==0){
            set1[j]=temp;
            j++;
        }
    }
    for(i=0;i<num1;i++){
        printf("%d",set1[i]);
    }

    //PROMPT FOR THE SECOND SET
    j=0;
    printf("\nEnter the size of the second set: ");
    scanf("%d",&num2);
    while(j<num2){
        exists=0;
        printf("\nEnter the element for the set: ");
        scanf("%d",&temp);
        for(i=0;i<num2;i++){
            if(temp==set2[i]){
                printf("\nThe element already exists.");
                exists=1;
            }
        }
        if(exists==0){
            set2[j]=temp;
            j++;
        }
    }
    for(i=0;i<num2;i++){
        printf("%d",set2[i]);
    }


    //GENERATE A BITSTRING FOR EACH SET    
    for(i=0;i<num;i++){
        bitstringset1[i]=0;
        for(j=0;j<num1;j++){
            if(uni[i]==set1[j]){
                bitstringset1[i]=1;
                break;
            }
        }
    }
    printf("\nfirst bitstring:");
    for(i=0;i<num;i++){
        printf("%d",bitstringset1[i]);
    }



    for(i=0;i<num;i++){
        bitstringset2[i]=0;
        for(j=0;j<num2;j++){
            if(uni[i]==set2[j]){
                bitstringset2[i]=1;
                break;
            }
        }
    }
    
    printf("\nsecond bitstring:\n");
    for(i=0;i<num;i++){
        printf("%d",bitstringset2[i]);
    }

//PROMPT FOR THE OPERATION TO BE PERFORMED
while(choice!=4){
        printf("\nWhat operation do you want to perform\n1. Union \t2. Intersection \t3.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                unionbitstr();
                break;
            case 2:
                intersection();
                break;
            case 3:
                break;
            default:
                printf("invalid choice!!");
        }
    }
}

//UNION OPERATION
void unionbitstr(){
    printf("\nUnion bitstring is: \n");
    for(i=0;i<num;i++){
        unionarray[i]=bitstringset1[i]|bitstringset2[i];
        printf("%d",unionarray[i]);
    }
}

//INTERSECTION OPERATION
void intersection(){
    printf("\nintersection bitstring is: \n");
    for(i=0;i<num;i++){
        intersectionarray[i]=bitstringset1[i]&bitstringset2[i];
        printf("%d",intersectionarray[i]);
    }
}