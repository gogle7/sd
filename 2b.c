#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
char *names[20], *temp;
int i,p,n;
printf("Enter the value for n\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
names[i] = (char*)malloc(30*sizeof(char));
}
printf("Enter %d names\n",n);
for(i=0;i<n;i++)
scanf("%s",names[i]);
for(p=0;p<n-1;p++)
{
for(i=0;i<n-1-p;i++)
{
if(strcmp(names[i], names[i+1])>0)
{
temp = names[i];
names[i] = names[i+1];
names[i+1] = temp;
}
}
}
printf("Sorted names\n");
for(i=0;i<n;i++)
{
printf("%s\n",names[i]);
}
}
