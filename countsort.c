#include<stdio.h>
int main()
{
   int a[100],n,i,b[100],c[100],r,max;
   printf("Enter Limit=");
   scanf("%d",&n);
   printf("Enter Range=");
   
   scanf("%d",&r);
   printf("Enter n numbers Within range=");
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
	c[i]=0;
   }
   for(i=0;i<n;i++)
   {
	c[a[i]]++;
   }
   for(i=1;i<=max;i++)
   {
	c[i]=c[i]+c[i-1];
   }
   for(i=n-1;i>=0;i--)
   {
	b[--c[a[i]]]=a[i];
   }
   printf("\n Sorted elements=\n");
   for(i=0;i<n;i++)
   printf("%d    ",b[i]);
}