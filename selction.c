#include<stdio.h>
int main()
{
	int min,i,j,t,n,a[20];
	printf("Enter Limit=");
	scanf("%d",&n);
	printf("Enter N numbers=");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	  {
	     min=i;
	     for(j=i+1;j<n;j++)
	       {
		  if(a[j]<a[min])
		     min=j;
	       }
	  if(min!=i)     
	  {
	  t=a[i];
	  a[i]=a[min];
	  a[min]=t;
	  }
	}
	printf("\nSORTED ORDER=\n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}