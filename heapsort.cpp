#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void buildheap(int a[],int n,int i)
{
    int large=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if((left<n) && (a[left]>a[large]))
    large=left;
    if((right<n) && (a[right]>a[large]))
    large=right;
    if(large != i)
    {
        swap(&a[i],&a[large]);
        buildheap(a,n,large);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        buildheap(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        buildheap(a,i,0);
    }
}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int a[10],i,n;
    printf("Enter Limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Number=");
        scanf("%d",&a[i]);
    }
    printf("Unsorted Display");
    display(a,n);
    heapsort(a,n);
    printf("\n\nSorted Display");
    display(a,n);
}