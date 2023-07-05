#include<stdio.h>
int main()
{
    int a[100],n,num,i,j,t;
    printf("Enter Limit=\n");
    scanf("%d",&n);
    printf("Enter N Numbers=\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        num=a[i];
        for(j=i-1;j>=0 && num<a[j];j--)
        {
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
        }
    }
    printf("\nSorted Elements=\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}