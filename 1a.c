#include<stdio.h>
#include<malloc.h>

int main()
{
    int i,n;
    float sum=0,*p;
    printf("Enter the number of items.\n");
    scanf("%d",&n);
    p=(float*)malloc(n*sizeof(int));
    if(p==NULL)
    {
        printf("Allocation Failed.\n");
        return 0;
    }
    printf("Enter the numbers to add.\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",(p+i));
    }
     for(i=0;i<n;i++)
    {
        sum += *(p+i);
    }
    printf("The sum of numbers is %f\n\n",sum);
    free(p);
}
