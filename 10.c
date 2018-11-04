#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int insert();
int del();
int show();
int rpt=1,q[SIZE];
int frnt,rear;
int main()
{
    frnt=rear=-1;
    int ch;
    while(rpt)
    {
        printf("A call center phone system using static QUEUE.\n");
        printf("Select a operation from the following:\n");
        printf("1:ADD incoming call\n2:Remove the call from the services\n3:Display pending calls\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                break;
            case 2: del();
                break;
                case 3: show();
                break;
                case 4: printf("END.\n");exit(0);
                break;
                default: printf("Please enter the correct \n");
                break;
        }
        printf("\n To continue press non zero digit:\n");
        scanf("%d",&rpt);
    }
}
int insert()
{
    int n;
    if(rear==(SIZE-1))
    {
        printf("Already queue is full.\n");
        return;
    }
    printf("Enter the call ID to be inserted to the system.\n");
    scanf("%d",&n);
    if(frnt==-1&&rear==-1)
    {
        rear++;
        frnt++;
        *(q+rear)=n;
        printf("Success.\n");
    }
    else
    {
        rear++;
        *(q+rear)=n;
        printf("Success.\n");
    }
    return;
}
int del()
{
    int temp;
    if(frnt==-1)
    {
        printf("No calls waiting in the queue.\n");
        return 0;
    }
    temp=*(q+frnt);
    frnt++;
    printf("Call answered is %d\n",temp);
    if(frnt>rear)
        frnt=rear=-1;
    return 0;

}
int  show()
{
    int i;
    if(frnt==-1&&rear==-1)
    {
        printf("Sorry no pending calls.\n");
        return 0;
    }
    printf("Here is the waiting queue of the calls.\n");
    printf("FRONT\t");
    for(i=frnt;i<=rear;i++)
        printf("%d\t",*(q+i));
    printf("REAR\n");
    return 0;
}
