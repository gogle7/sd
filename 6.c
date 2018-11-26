#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct book
{
	int isbn;
	float price;
	char name[30];
};
struct stack
{
	struct book bk[SIZE];
	int top;
};
void push(struct stack *ps,struct book bk1)
{
	if((ps->top)>=(SIZE-1))
	{
		printf("Stack Overflow.\n");
		exit(0);
	}
	else
	{
		++(ps->top);
		strcpy(ps->bk[ps->top].name,bk1.name);
		ps->bk[ps->top].isbn=bk1.isbn;
		ps->bk[ps->top].price=bk1.price;
	}
}
struct book pop(struct stack *ps)
{
	struct book bo;
	strcpy(bo.name,ps->bk[ps->top].name);
	bo.isbn=ps->bk[ps->top].isbn;
	bo.price=ps->bk[ps->top].price;
	(ps->top)--;
	return(bo);
}
int main()
{
	struct stack s;
	struct book bk1,bk2;
	s.top=-1;
	int i,n=0;
	while(n!=4)
	{
		printf("\nEnter the choice.\n1.Push\n2.Pop\n3.Display\n4.Exit.\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("\nEnter the details.(Book Name,ISBN,Price)\n");
				scanf("%s%d%f",bk1.name,&bk1.isbn,&bk1.price);
				push(&s,bk1);
				break;
			case 2:if(s.top==-1)
					printf("Stack Underflow\n");
				else
				{
					bk2=pop(&s);
					printf("Followings are popped out from Stack.\n");
					printf("\nBook Name:%s\t\nISBN:%d\t\nPrice:%.2f\t\n\n",bk2.name,bk2.isbn,bk2.price);
				}
				break;
			case 3:if(s.top==-1)
					printf("Stack is empty.\n");
				else
				{
					printf("Stack contents are:\n");
					for(i=s.top;i>=0;i--)
						printf("\nBook Name:%s\t\nISBN:%d\t\nPrice:%.2f\t\n\n",s.bk[i].name,s.bk[i].isbn,s.bk[i].price);
				}
				break;
			case 4: printf("Exiting from the program.\n");
					exit(0);
					break;
			default:printf("Invalid choice made.Please try again.\n\n");
		}

	}
}
