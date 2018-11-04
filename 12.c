#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stud{
    int id;
    char name[10];
    int sem;
    struct stud *next;
};
typedef struct stud NODE;
NODE* head;
NODE* insert()
{
    NODE *temp1,*temp2,*n;
    n=(NODE *)malloc(sizeof(NODE));
    printf("Enter thee students data in order.\n");
    printf("Enter the Student ID.\n");
    scanf("%d",&n->id);

    printf("Student Name.\n ");
    scanf("%s",n->name);

    printf("Semester.\n");
    scanf("%d",&n->sem);

    n->next=NULL;

    if(head==NULL)
        head=n;
    else if(strcmp(head->name,n->name)>0)
    {
        n->next=head;
        head=n;
    }
    else
    {
        for(temp1=NULL,temp2=head;temp2!=NULL&&strcmp(n->name,temp2->name)>0;temp2=temp2->next)
        {
            temp1=temp2;
        }
        temp1->next=n;
        n->next=temp2;
    }
    return(head);
}
int del()
{
    NODE *temp1,*temp2;
    char name[10];
    int flag=0;
    if(head==NULL)
    {
        printf("Empty.\n");
        return 0;
    }
    printf("Enter the name for deletion.\n");
    scanf("%s",name);
    if(strcmp(head->name,name)==0)
    {
        head=head->next;
        printf("Deleted.\n");
    }
    else
    {
        for(temp1=NULL,temp2=head;temp2!=NULL;temp2=temp2->next)
        {
            if(strcmp(name,temp2->name)==0)
            {
                flag=1;
                break;
            }
            else
                temp1=temp2;
        }
        if(flag==0)
        {
            printf("Student name %s 's record not present in the list.\n",name);
            return 0;
        }
        temp1->next=temp2->next;
        printf("%s student's data has been deleted.\n",temp2->name);
        free(temp2);
    }
    return 0;
}
int show()
{
    NODE *N;
    if(head==NULL)
    {
        printf("EMPTY\n");
        return 0;
    }
    printf("%-15s%-20s%-10s\n","NAME","ID","SEM");
    N=head;
    while(N!=NULL)
    {
        printf("%-15s%-20d%-10d\n",N->name,N->id,N->sem);
        N=N->next;
    }
    return 0;
}
int main()
{
    int ch=0;
    printf("1.Insert a New Name\n2.Delete a Name\n3.Display\n4.Exit\n");
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
