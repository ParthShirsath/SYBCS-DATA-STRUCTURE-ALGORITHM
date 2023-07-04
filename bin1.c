#include<stdio.h>
int main(){
    int num,n,i,flag;
    int search(int num,int n,int a[n]);
    printf("Enter Limit=");
    scanf("%d",&n);
    int a[n];
    printf("Enter N number an Array=");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter Number To found=");
    scanf("%d",&num);
    flag=search(num,n,a);
    if(flag==1)
    printf("Number Is Found....");
    else
    printf("Number Is Not Found....");
}
int search(int num,int n,int a[n])
{
    int top=0,bottom=n-1,mid,flag=0;
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(a[mid]==num)
        {
            flag=1;
            break;
        }
        if(num>a[mid])
        top=mid+1;
        else
        bottom=mid-1;
    }
    return flag;
}

