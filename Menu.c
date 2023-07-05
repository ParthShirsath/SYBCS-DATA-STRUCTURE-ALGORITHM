#include<stdio.h>
int main()
{
    int n,a[100],ch,i,num;
    void insertion(int a[100],int n);
    void bubble(int a[100],int n);
    void selection(int a[100],int n);
    void linier(int a[100],int n,int num);
    printf("Enter Limit=");
    scanf("%d",&n);
    printf("ENter N Number");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    do{
    printf("Menu-\n1-Insertion Sort\n2-bubble Sort\n3-selection Sort\n4-linear search\nEnter Your Choice=");
    scanf("%d",&ch);
    switch(ch)
    {
    
        case 1:insertion(a,n);
               break;
        case 2:bubble(a,n);
               break;
        case 3:selection(a,n);
               break;
        case 4:printf("Enter Number to Search=");
               scanf("%d",&num);
               linier(a,n,num);
               break;
        default:printf("Invalid Choice........!");
        }
    }while(ch<5);
}

void insertion(int a[100],int n)
{
    int i,j,num,t;
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
    printf("\nSorted Numbers=\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}

void bubble(int a[100],int n)
{
    int i,pass,t;
    for(pass=1;pass<n;pass++)
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
    printf("\nSorted Numbers=\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}

void selection(int a[100],int n)
{
    int i,j,min,t,index;
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
    printf("\nSorted Numbers=\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}

void linier(int a[100],int n,int num)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    printf("Number Is Found\n");
    else
    printf("Number Is Not Found\n");
}