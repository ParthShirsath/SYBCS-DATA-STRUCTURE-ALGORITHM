#include<stdio.h>
struct emp{
   int age;
   char name[20];
}e1[100],t;
void bubble(struct emp e1[100],int n)
{
   int pass,i;
   for(pass=1;pass<n;pass++)
   {
      for(i=0;i<n-pass;i++)
      {
        if(e1[i].age>e1[i+1].age)
	 	{
		t=e1[i];
		e1[i]=e1[i+1];
		e1[i+1]=t;
	 	}
      }	   
   }
   for(i=0;i<n;i++)
   {
	printf("\n%s	%d",e1[i].name,e1[i].age);
   }
}

void insertion(struct emp e1[100],int n)
{
	int i,j,age1;
	for(i=1;i<n;i++)
	{
		age1=e1[i].age;
		for(j=i-1;j>=0&&e1[j].age>age1;j--)
		{
			t=e1[j+1];
			e1[j+1]=e1[j];
			e1[j]=t;
		}
	}
	
    for(i=0;i<n;i++)
    {
		printf("\n%s	%d",e1[i].name,e1[i].age);
    }
}

void selection(struct emp e1[100],int n)
{
	int i,j,min,index;
	for(i=0;i<n;i++)
	{
		min=e1[i].age;
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(e1[j].age<min)
			{
				min=e1[j].age;
				index=j;
			}
		}
		t=e1[i];
		e1[i]=e1[index];
		e1[index]=t;
	}
	  for(i=0;i<n;i++)
   {
	printf("\n%s	%d",e1[i].name,e1[i].age);
   }
}
void conqure(struct emp e1[100],int start,int mid,int bottom)
{
struct emp a[100];
	int i=start,j=mid+1,k=0;
		while(i<=mid&&j<=bottom)
	{
		if(e1[i].age<e1[j].age)
		a[k++]=e1[i++];
		else
		a[k++]=e1[j++];
	}
	while(i<=mid)
	a[k++]=e1[i++];
	
	while(j<=bottom)
	a[k++]=e1[j++];
	
   	  for(i=0;i<k;i++)
	  {
		 e1[start+i]=a[i];
	  }
}
void divide(struct emp e1[100],int start,int bottom)
{
	int mid;
	if(start<bottom)
	{
		mid=(start+bottom)/2;
		divide(e1,start,mid);
		divide(e1,mid+1,bottom);
		conqure(e1,start,mid,bottom);
	}
}
void count(struct emp e1[100],int n)
{
	int i,max;
	struct emp b[100];
	max=e1[0].age;
	for(i=1;i<n;i++)
	{
		if(e1[i].age>max)
		max=e1[i].age;
	}
	struct emp c[max+1];
    for(i=0;i<=max;i++)
	{
        c[i].age = 0;
    }
	for(i=0;i<n;i++)
	{
		c[e1[i].age]++;
	}
	int index = 0;
  for(int j=0;j<=max;j++) 
  {
    for (int k=0;k<c[j];k++)
	 {
      b[index++]=e1[j];
     }
  }
}
int main()
{
   FILE *fp1;
   int i=0;
   fp1=fopen("emp.txt","r");
   if(fp1==NULL)
   {
	printf("File Is Empty");
   }
   while(!feof(fp1))
   {
        fscanf(fp1,"%s%d",&e1[i].name,&e1[i].age);
	i++;
   }
   int n=i-1;
   printf("\nORIGINAL DATA:");
   
   for(i=0;i<n;i++)
   {
	printf("\n%s	%d",e1[i].name,e1[i].age);
   }
    printf("\n\n");
   printf("\nBUBBLE SORTED DATA:");
   bubble(e1,n);
   printf("\n\n");
   printf("\nSELECTION SORTED DATA:");
   selection(e1,n);
   printf("\n\n");
   printf("\nINSERTION SORTED DATA:");
   insertion(e1,n);
   printf("\n\n");
   printf("\nMERGE SORTED DATA:");
   divide(e1,0,n);
    for(i=1;i<=n;i++)
      {
	     printf("\n%s	%d",e1[i].name,e1[i].age);
      }
   printf("\n\n");
   printf("\nCOUNT SORTED DATA:");
   count(e1,n);
   fclose(fp1);
}
