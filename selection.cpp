#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,min,a[100],t,index,j;
	printf("Enter Limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	for(i=0;i<n;i++)
	{
		min=a[i];
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				index=j;
			}
		}
	t=a[i];
	a[i]=a[index];
	a[index]=t;
	}
	printf("\nSorted Array");
	for(i=0;i<n;i++)
	{
		printf("%d     ",a[i]);
	}
}
