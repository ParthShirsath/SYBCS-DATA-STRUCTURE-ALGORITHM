#include<stdio.h>
int main()
{
    int n,top,bottom,num,i,mid,flag=0;
    printf("Enter Limit=\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter N number In An Array=\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter Number To Search=\n");
    scanf("%d",&num);
    top=0;
    bottom=n-1;
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(num==a[mid])
        {
            flag=1;
            break;
        }
        if(num>a[mid])
        top=mid+1;
        else
        bottom=mid-1;
    }
    if(flag==1)
    printf("Number Is Found.....");
    else
    printf("Number Is Not Found..........!");
}
