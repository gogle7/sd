#include<stdio.h>
#include<stdlib.h>

struct stack{

int item;
struct stack *link;
};

typedef struct stack stk;
stk *top=NULL; 
//here top can be represented as a head 

void insert();
int del();
void show();


void main()
{

    int ch=0;
    printf("1.Insert a New item\n2.Delete a item \n3.Display \n4.Exit\n");
    while(ch!=4)
    {
        printf("\nEnter the choice.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
            break;
            case 2:del();
            break;
            case 3:show();
            break;
            case 4:printf("END.\n");
                    exit(0);
            break;
            default:printf("Please Enter the correct choice.\n");
        }
    }
}

void insert(){
    stk *new;
    int ele;
    new=(stk *)malloc(sizeof(stk));\
    if(new==NULL){
    	printf("The allocation failed\n");
    	exit(0);
    }
    printf("Enter the element\n");
    scanf("%d",&ele);
    new->item=ele;
    new->link=NULL;
    if(top=NULL){

        top=new;
    }
    else{
        new->link=top;
        top=new;
    }
}

int del(){
stk *tem;
if(top==NULL){
    printf("Stack uderflow \n");
    return 0;
}
tem=top;
top=top->link;
free(tem);
}

void show(){
	if(top==NULL){
	 printf("stack underflow\n");
	 exit(0);
	}
	stk *tem;
	tem=top;
	while(tem!=NULL){
		printf("The item is %d \n",tem->item);
		tem=tem->link;
	}
}
