#include <stdio.h>
int main()
{
int i,a[100],n,c1=0,c2=0;
printf("enter the limit=");
scanf("%d",&n);
printf("enter the numbers=");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
if(a[i]%2==0)
c1++;
else
c2++;	
}
printf("\neven count=%d",c1);
printf("\nodd count=%d",c2);
}

