#include<stdio.h>
int main()
{
    int n,i,pass,t;
    printf("enter Limit");
    scanf("%d",&n);
    int a[n];
    printf("Enter N numbers in An Array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(pass=0;pass<n;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(a[i]>a[i+1])
            {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
            }
        }
    }
    printf("Numbers In Sorted Order=\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}