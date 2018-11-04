#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct item
{
		int ele;
};
struct cqueue
{
		struct item it[SIZE];
		int front;
		int rear;
};
void insert(struct cqueue *pq,int x);
int del(struct cqueue *pq);
void main()
{
		struct cqueue cq;
		int x,choice,r;
		cq.front=SIZE-1,cq.rear=SIZE-1;
		do
		{
				printf("......MENU.....\n");
				printf("Enter your choice\n1.INSERT\n2.REMOVE\n3.QUIT\n");
				scanf("%d",&choice);
				switch(choice)
				{
						case 1:printf("Enter the item to be inserted\n");
							scanf("%d",&x);
							insert(&cq,x);
							break;
					    case 2:if(cq.front==cq.rear)
					       		printf("Queue underflow\n");
					       		else
					       		{
					       		r=del(&cq);
					       		printf("The item deleted is %d\n",r);
					       		}
					       		return;
					    case 3:printf("Quitting operation queue\n");
					           break;
					    default:printf("Invalid choice\n");
					           break;
					           }
		}while(choice!=3);
		}
		void insert(struct cqueue *pq,int x)
		{
		if(pq->rear==(SIZE-1))
		  pq->rear=0;
		else
		  (pq->rear)++;
		 if(pq->front==pq->rear)
		 {
		 	printf("Circular queue overflow\n");
			 exit(1);
		 }
		 pq->it[pq->rear].ele=x;
		 return;
	 }
	 int del(struct cqueue *pq)
	 {
     if(pq->front==(SIZE-1))
		pq->front=0;
	else
	 (pq->front)++;
	 return (pq->it[pq->front].ele);
	 }

