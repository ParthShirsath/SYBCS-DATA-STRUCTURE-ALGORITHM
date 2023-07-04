#include<stdio.h>
int main()
{
    int n,i,j,min,t,index;
    printf("Enter Limit");
    scanf("%d",&n);
    int a[n];
    printf("Enter N number In an array=\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        min=a[i];
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                index=j;
            }
        }
        t=a[i];
        a[i]=a[index];
        a[index]=t;
    }
    printf("NUmbers In Sorted Order=\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}