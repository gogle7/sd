#include<stdio.h>
#include<malloc.h>

int main()
{
    int (*p)[10];
    int i,j,m,n;
    int psum=0,ssum=0,tsum=0;
    printf("\n\nEnter the order of the matrix.\n");
    scanf("%d%d",&m,&n);
    if(m!=n)
    {
        printf("The order of the matrix is not same. So, it is not a square matrix.\n");
        return 0;
    }
    p=malloc(m*n*sizeof(int));
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
    
    printf("The matrix is:\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(*(p+i)+j));
        }
        printf("\n");
    }
    
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
   
     for(i=0,j=n-1;i<m&&j>=0;i++,j--)
     {
         ssum= ssum+*(*(p+i)+j);
     }
      
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
