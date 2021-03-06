#include <stdio.h>
#include <stdlib.h>

int bin(int a[],int key,int low, int high)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(key==a[mid])
        return mid;
    if(key<a[mid])
        return(bin(a,key,low,mid-1));
    return (bin(a,key,mid+1,high));
}
int main()
{
    int key,i,n,*a,low,high,res,p=0;
    printf("Enter the n.\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers.\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    
    printf("Enter the key elements.\n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    res=bin(a,key,low,high);
    if(res==-1)
        printf("Key not found.\n");
    else
        printf("Element is found at %d.",res+1);
}
