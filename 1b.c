/*1.b. Find the following for the matrix use pointer concept of 2D array.
1. Sum of principle diagonal elements.
2. Sum of secondary diagonal elements
3. Sum of all elements. */
#include<stdio.h>
#include<malloc.h>

int main()
{
    int (*p)[10];
    int i,j,m,n;
    int psum=0,ssum=0,tsum=0;
    printf("1.b. Find the following for the matrix use pointer concept of 2D array.\n1. Sum of principle diagonal elements.\n2. Sum of secondary diagonal elements\n3. Sum of all elements. ");
    printf("\n\nEnter the order of the matrix.\n");
    scanf("%d%d",&m,&n);
    if(m!=n)
    {
        printf("The order of the matrix is not same. So, it is not a square matrix.\n");
        return 0;
    }
    p=(int*)malloc(m*n*sizeof(int));
    if(p==NULL)
    {
        printf("Allocation Failed\n");
        return 0;
    }
    printf("Enter the elements of the matrix.\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",*(p+i)+j);
        }
    }
    /*For printing matrix.*/
    printf("The matrix is:\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(*(p+i)+j));
        }
        printf("\n");
    }
    /*For principle diagonal matrix.*/
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                psum= psum + *(*(p+i)+j);
            }
        }
    }
     /*For secondary diagonal matrix.*/
     for(i=0,j=n-1;i<m&&j>=0;i++,j--)
     {
         ssum= ssum+*(*(p+i)+j);
     }
      /*For total sum matrix.*/
     for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
        {
            tsum=tsum+*(*(p+i)+j);
        }
     }
     printf("\nThe sum of principle diagonal elements =%d\n",psum);
     printf("The sum of secondary diagonal elements =%d\n",ssum);
     printf("The sum of total elements of the matrix =%d\n",tsum);


}
