#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct employee{
	char name[30],dept[30];
	int id;
	float salary;
};

int salar(struct employee *e,int n);

void main()
{
	struct employee *e;
	int i,n;
	printf("Enter the number of Employee.\n");
	scanf("%d",&n);
	e=(struct employee *)malloc(n*sizeof(struct employee));
	if(e==NULL)
	{
		printf("Allocation Failed.\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the Id,Name,Department and Salary of the %d employee.\n",i+1);
		scanf("%d%s%s%f",&(e+i)->id,(e+i)->name,(e+i)->dept,&(e+i)->salary);
	}
	printf("The details of the employee are:\n");
	for(i=0;i<n;i++)
	{
		printf(" Employee Id: %d \n Employee Name: %s\n Employee Department: %s\n Employee Salary:%f\n\n",(e+i)->id,(e+i)->name,(e+i)->dept,(e+i)->salary);
	}
	
	salar(e,n);
	
}

int salar(struct employee *temp,int n)
{
	int i=0;
	float ts=0;
	char dept_str[30];
	printf("Enter the department for total salary.\n");
	scanf("%s",dept_str);
	for(i=0;i<n;i++)
	{
		if(strcmp((temp+i)->dept,dept_str)==0)
		{
			ts=ts+(temp+i)->salary;	
		}	
	
	}
	printf("The total salary of %s department is %f\n",dept_str,ts);
}

