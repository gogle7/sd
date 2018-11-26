#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
struct item{
	int ele;
};
struct cqueue{
	struct item it[maxsize];
	int front;
	int rear;
};
void insertitem(struct cqueue *pq,int x);
int deleteitem(struct cqueue *pq);
void main()
{
	struct cqueue cq;
	int x;
	int choice;
	int r;
	cq.front=maxsize-1,cq.rear=maxsize-1;
	do{
		printf("\n1.insert\t2:remove\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the item to be inserted:");
			scanf("%d",&x);
			insertitem(&cq,x);
			break;
			case 2:if(cq.front==cq.rear)
			printf("queue underflow\n");
			else
			{
				r=deleteitem(&cq);
				printf("the item deleted is %d\n",r);
			}
			break;
			default:printf("no such options\n");
		}
	}while(choice!=3);
}
void insertitem(struct cqueue *pq,int x)
{
	if(pq->rear==maxsize-1)
	pq->rear=0;
else
	(pq->rear)++;
if(pq->rear==pq->front)
{
	printf("circular queue overflow\n");
		exit(1);
}
pq->it[pq->rear].ele=x;
}

int deleteitem(struct cqueue *pq)
{
	if(pq->front==maxsize-1)
		pq->front=0;
	else
		(pq->front)++;
	return(pq->it[pq->front].ele);
}
