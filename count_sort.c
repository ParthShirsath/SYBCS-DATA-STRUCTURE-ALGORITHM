#include<stdio.h>
int main()
{
	int i,n,max,a[100],b[100],cnt[100];
	printf("Enter Limit=");
	scanf("%d",&n);
	printf("Enter N numbers");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	for(i=0;i<=max;i++)
	{
		cnt[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cnt[a[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		cnt[i]=cnt[i]+cnt[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		b[--cnt[a[i]]]=a[i];
	}
	printf("\nSorted Array=");
	for(i=0;i<n;i++)
	{
		printf("%d    ",b[i]);
	}
}
