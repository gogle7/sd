#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void strcopy(char *a,char *b);
int strcomp(char *a,char *b);
void strconcat(char *a,char *b);
void strreverse(char *a);
	
int main()
{
	char a[80],b[80],c[50];
	char result;
	int choice;
	while(1)
	{
	printf("\nn1.strcpy\nn2.strcomp\nn3.strconcat\nn4.strreverse\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("enter the string to be copied\n");
			scanf("%s",b);
			strcopy(a,b);
			printf("after copying the string is a=%s",a);
			break;
		case 2:
			printf("enter the first string\n");
			scanf("%s",a);
			printf("enter the second string\n");
			scanf("%s",b);
			result=strcomp(a,b);
			if(result>0)
			printf("the string %s is greater than string %s",a,b);
			else if(result<0)
			printf("the string %s is greater than string %s",b,a);
			else
			printf("the string %s and %s are equal",a,b);
			break;
		case 3:
			printf("enter the string a\n");
			scanf("%s",a);
			printf("enter the string b\n");
			scanf("%s",b);
			strconcat(a,b);
			printf("the string after concatination is %s",a);
			break;
		case 4:
			printf("enter the string to be reversed\n");
			scanf("%s",a);
			strreverse(a);
			printf("the string after reversing is %s",a);
			break;
		default:printf("enter the correct choice\n");
		}
	}

}

	//strcopy
void strcopy(char *a,char *b)
{
	
	while(*b!='\0')
	{
	*a=*b;
	++a;
	++b;
	}
	*a='\0';
	
}

	//strcomp
int strcomp(char *a,char *b)
{
	char result;
	while(*a!='\0'||*b!='\0')
	{
	if(*a!=*b)
	result=(*a-*b);
	 a++;
	b++;
	return result;
	
	}
	return 0;
	
}
	
	//strconcat
void strconcat(char *a,char *b)
{
	
			
	while(*a!='\0')
	a++;
	while(*b!='\0')
	{
	*a=*b;
	a++;
	b++;
	}
	*a='\0';
	
}
	//strreversechar 
void strreverse(char *a)
{
	
	
	int i,j,k=0;char c[50];	
	while(*a!='\0')
	{
	a++,k++;
	}
	 for(i=0,j=k-1;j>=0;j--,i++)
	{
	--a;
	c[i]=*a;
	}
	c[i]='\0';
	strcpy(a,c);	
}

