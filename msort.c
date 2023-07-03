#include<stdio.h>
int main()
{
    int n1,n2,n3,i,j,k;
    printf("Enter Limit for First And Second Array=");
    scanf("%d%d",&n1,&n2);
    int a[n1],b[n2];
    printf("Enter N number in First Array=\n");
    for(i=0;i<n1;i++)
    scanf("%d",&a[i]);
    printf("Enter N number in Second Array=\n");
    for(i=0;i<n2;i++)
    scanf("%d",&b[i]);
    n3=n1+n2;
    int c[n3];
    i=j=k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    while(i<n1)
    {

            c[k++]=a[i++];
    }
    while(j<n2)
    {
        c[k++]=b[j++];
    }   
    printf("Numbers In Sorted Order=\n");
    for(i=0;i<n3;i++)
    printf("%d  ",c[i]);
}