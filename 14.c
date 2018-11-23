#include<stdio.h>
#include<stdlib.h>
struct dll
{
    int info;
    struct dll *left;
    struct dll *right;
};
typedef struct dll NODE;
NODE *head=NULL;
void main()
{
    int rpt=1;
    int ch,data;
    printf("Enter integer to create DLL\n");
    scanf("%d",&data);
    do
    {
        create(data);
        scanf("%d",&data);
    }while(data!=999);
    show();
    printf("1.Insert to left.\n2.Delete\n3.Display\n4.Exit\n");
    while(rpt)
    {
        printf("Enter the choice.\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:del();
            break;
            case 3:show();
            break;
            case 4:printf("END\n");
            break;
            default:printf("Enter the correct option.\n");
        }
    }
}
create(int d)
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->info=d;
    temp->left=NULL;
    temp->right=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->right=head;
    head->left=temp;
    head=temp;
    return;
}
insert()
{
    NODE *new, *temp, *temp2;
    int key,flag=0;
    new=(NODE *)malloc(sizeof(NODE));
    printf("Enter the integer of new node.\n");
    scanf("%d",&new->info);
    new->left=NULL;
    new->right=NULL;
    if(head==NULL)
       {
           head=new;
           return;
       }
    printf("Enter the key value of existing node.\n");
    scanf("%d",&key);
    if(key==head->info)
    {
        head->left=new;
        new->right=head;
        head=new;
    }
    else
    {
        for(temp=head->right;temp!=NULL;temp=temp->right)
        {
            if(temp->info==key)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            temp2=temp->left;
            new->left=temp2;
            new->right=temp;
            temp2->right=new;
            temp->left=new;
        }
        else
            printf("Give proper input.\n");
    }
    return;
}
del()
{
    NODE *temp;
    int flag=0,key;
    if(head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    printf("Enter the key value of existing node.\n");
    scanf("%d",&key);
    if(key==head->info)
    {
        temp=head;
        head=head->right;
        if(head!=NULL)
            head->left=NULL;
        free(temp);
    }
    else
    {
        for(temp=head->right;temp!=NULL;temp=temp->right)
        {
            if(temp->info==key)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            if(temp->right==NULL)
                temp->left->right=NULL;
            else
            {
                temp->left->right=temp->right;
                temp->right->left=temp->left;
            }
            printf("Node with key value %d has been deleted.\n",key);
            free(temp);
        }
        else
            printf("Node not found.\n");
    }
    return;
}
show()
{
    NODE *temp;
    if(head==NULL)
        printf("EMPTY.\n");
    else
    {
        printf("Double Linked List.\nSTART<-->");
        for(temp=head;temp!=NULL;temp=temp->right)
            printf("%d<-->",temp->info);
        printf("END\n");
    }
    return;
}
