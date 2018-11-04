#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void main()
{
int *A[10], *B[10], *C[10];
int i,j,k,m,n,p,q;
printf("Enter the order of first matrix\n");
scanf("%d%d", &m,&n);
printf("Enter the order of second matrix\n");
scanf("%d%d", &p,&q);
if(n!=p)
{
printf("Matrices cant be multiplied\n");
return;
}
else
{
for(i=0;i<m;i++)
{
A[i] = (int*)malloc(n*sizeof(int));
}
for(i=0;i<p;i++)
{
B[i] = (int*)malloc(q*sizeof(int));
}
for(i=0;i<m;i++)
{
C[i] = (int*)malloc(q*sizeof(int));
}
printf("Enter the first matrix elements\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d", *(A+i)+j);
}
}
printf("Enter the second matrix elements\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
scanf("%d", *(B+i)+j);
}
}
printf("The first matrix elements\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t", *(*(A+i)+j));
}
printf("\n");
}
printf("The Second matrix elements\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
printf("%d\t", *(*(B+i)+j));
}
printf("\n");
}
for(i=0;i<m;i++)
{
    for(j=0;j<q;j++)
    {
    *(*(C+i)+j)=0;
    for(k=0;k<n;k++)
    {
        *(*(C+i)+j) += (*(*(A+i)+k) * *(*(B+k)+j));
    }
    }
}
printf("The product is : \n");
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{
printf("%d\t", *(*(C+i)+j));
}
printf("\n");
}
}
}
