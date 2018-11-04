//1.a.Program to find the sum of 'n' numbers allocate the memory dynamically to the numbers.\n\n");
#include<stdio.h>
#include<malloc.h>/*Header file for DMA*/

int main()
{
    int i,n;
    float sum=0,*p;
    printf("\n\n1.a.Program to find the sum of 'n' numbers allocate the memory dynamically to the numbers.\n\n");
    printf("Enter the number of items.\n");
    scanf("%d",&n);
    p=(float*)malloc(n*sizeof(int));/*Dynamic Memory Allocation*/
    if(p==NULL)/*Checking whether pointer is NULL or not (only for negative.)*/
    {
        printf("Allocation Failed.\n");
        return 0;
    }
    printf("Enter the numbers to add.\n");
    for(i=0;i<n;i++)/*for getting numbers */
    {
        scanf("%f",(p+i));
    }
     for(i=0;i<n;i++)/*for sum*/
    {
        sum += *(p+i);
    }
    printf("The sum of numbers is %f\n\n",sum);
    free(p);/*Pointer free*/
}
