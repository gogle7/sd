#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 10
struct student
{
	char name[50];
	char usn[10];
};
struct stack
{
	struct student max[size];
	int top;
}; 
void push(struct stack *sp,struct student st1);
struct student pop(struct stack *sp);
int main()
{
	int i;
	struct stack s;
	struct student st1;
	struct student rt1;
	s.top=-1;
while(1)
{
	int choice;
	printf("\n 1.push\n 2.pop\n 3.display\n 4.quit\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
switch(choice)
{
	case 1:
		printf("enter the name and usn of the student to be pushed\n");
		scanf("%s%s",st1.name,st1.usn);
		push(&s,st1);
		break;
	case 2:
		rt1=pop(&s);
		printf("the poped name %s with usn %s\n",st1.name,st1.usn);
	case 3:printf("the stack contents are listed\n");
		for(i=s.top;i>=0;i--)
		{
		printf("%s\n%s\n",s.max[i].name,s.max[i].usn);
		}
		break;
	case 4:
		printf("operation finished\n thank u!");
		break;		
	 	default:printf("please enter the above choices\n");
exit(0);
}
}
	return 0;
}
void push(struct stack *sp,struct student st1)
{
if(sp->top==size-1)
{
	printf("stack overflow\n");
	exit(1);
}
else
{
	++(sp->top);
	strcpy(sp->max[sp->top].name,st1.name);
	strcpy(sp->max[sp->top].usn,st1.usn);
}
}
struct student pop(struct stack *sp)
{

	struct student s;
	strcpy(s.name,sp->max[sp->top].name);
	strcpy(s.usn,sp->max[sp->top].usn);
	(sp->top)--;
	return(s);
} 
