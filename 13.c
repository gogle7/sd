#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct stack
{
int data;
struct stack *next;
};
typedef struct stack NODEPTR;
NODEPTR *top = NULL;
NODEPTR *push(NODEPTR *, int);
NODEPTR *display(NODEPTR *);
NODEPTR *pop(NODEPTR *);

int main() {
int val;
int option;
printf("\n *****MAIN MENU*****");

printf("\n 1. PUSH");

printf("\n 2. POP");
printf("\n 3. DISPLAY");

printf("\n 4. EXIT");
do
{
printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
		case 1:

printf("\n Enter the number to be pushed on stack: ");
			scanf("%d", &val);

top = push(top, val);
			break;
		case 2:
			top = pop(top);
			break;
		if (val != -1)
printf("\n The value at the top of stack is: %d", val);
else
printf("\n STACK IS EMPTY");
	break;
case 3:
		top = display(top);
			break;
		}
}while(option != 4);
return 0;
}
NODEPTR *push(NODEPTR *top, int val)
{
    NODEPTR *ptr;
    ptr = (NODEPTR*)malloc(sizeof(NODEPTR));
    ptr -> data = val;
    if(top == NULL)
    {

    ptr -> next = NULL;

    top = ptr;
    }
    else
    {

    ptr -> next = top;

    top = ptr;
    }
return top;
}
NODEPTR *display(NODEPTR *top)
{
    NODEPTR *ptr;
    ptr = top;
    if(top == NULL)
        printf("\n STACK IS EMPTY");
    else
    {
    while(ptr != NULL)
    {
        printf("\n %d", ptr -> data);
        ptr = ptr -> next;
    }
}
return top;
}
NODEPTR *pop(NODEPTR *top)
{
    NODEPTR *ptr;
    ptr = top;
    if(top == NULL)
    printf("\n STACK UNDERFLOW");
    else
    {
        top = top -> next;
        printf("\n The value being deleted is: %d", ptr -> data);
            free(ptr);
    }
    return top;
}
