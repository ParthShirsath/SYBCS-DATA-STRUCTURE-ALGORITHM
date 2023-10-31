#include<stdio.h>
int main()
{
	int min,i,j,t,n,a[20];
	printf("Enter Limit=");
	scanf("%d",&n);
	printf("Enter N numbers=");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	  {
	     min=a[i];
	     for(j=i-1;j>=0 && num<a[j];j--)
		{
		   t=a[j+1];
		   a[j+1]=a[j];
		   a[j]=t;
		}
	  }
	printf("\nSORTED ORDER=\n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}