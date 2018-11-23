#include<stdio.h>
struct node
{
	int info;
	struct node *lt, *rt;
};
struct node *root=NULL;
void bst(int);
struct node *maketree(int);
void setleft(struct  node*,int);
void setright(struct  node*,int);
void inorder(struct  node*);
void preorder(struct  node*);
void postorder(struct  node*);

void main()
{
	int ch,x;
	while(1)
	{
	     printf("\n1:CREATE-TREE\n 2:INORDER\n 3:PREORDER\n 4:POSTORDER\n  5:EXIT\n");
		printf("Enter your choice\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be inserted\n\n");
				scanf("%d",&x);
				bst(x);
				break;

			case 2:
				if(root==NULL)
				printf("\nTree doesn't exist\n\n");
				else
				{
					printf("\nInorder Traversal is\n\n");
					inorder(root);
				}
				break;
			case 3:
				if(root==NULL)
				printf("\nTree doesn't exist\n\n");
				else
				preorder(root);
				break;

			case 4:
				if(root==NULL)
				printf("\nTree doesn't exist\n\n");
				else
				postorder(root);
				break;

			case 5:
				exit(1);

			default:
				printf("\nInvalid choice\n\n");

		}
	}
}

void bst(int x)
{
	struct node *p, *q;
	if(root==NULL)
	root=maketree(x);
	else
	{
		p=q=root;
		while(q!=NULL)
		{
			p=q;
			if(p->info>x)
			q=p->lt;
			else
			q=p->rt;
		}
		if(p->info<=x)
		setright(p,x);
		else
		setleft(p,x);
	}
}

struct  node* maketree(int x)
{
	struct node *p;
	p=( struct  node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("\nMemory can't be allocated\n\n");
		return 0;
	}
	p->info=x;
	p->lt=p->rt=NULL;
	return p;
}

void setleft(struct  node *p,int x)
{
	if(p==NULL)
	printf("\nInsertion is not possible\n\n");
	else
	if(p->lt!=NULL)
	printf("\nLeft node already exists\n\n");
	else
	p->lt=maketree(x);
}

void setright(struct  node *p,int x)
{
	if(p==NULL)
	printf("\nInsertion is not possible\n\n");
	else
	if(p->rt!=NULL)
	printf("\nRight node already exists\n\n");
	else
	p->rt=maketree(x);
}

void inorder(struct  node* p)
{
	if(p!=NULL)
	{
		inorder(p->lt);
		printf("%d ",p->info);
		inorder(p->rt);
	}
}

void preorder(struct  node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->info);
		preorder(p->lt);
		preorder(p->rt);
	}
}
void postorder(struct  node *p)
{
	if(p!=NULL)
	{
		postorder(p->lt);
		postorder(p->rt);
		printf("%d ",p->info);
	}
}
