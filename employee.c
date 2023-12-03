#include<stdio.h>
struct emp{
    int age;
    char name[20];
}e1[100],e2[100];
int count(struct emp e1[100],int n)
{
	int max,i,cnt[100];
	max=e1[0].age;
	for(i=0;i<n;i++)
	{
		if(e1[i].age>max)
		max=e1[i].age;
	}
	for(i=0;i<=max;i++)
	{
		cnt[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cnt[e1[i].age]++;
	}
	for(i=1;i<=max;i++)
	{
		cnt[i]=cnt[i]+cnt[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		e2[--cnt[e1[i].age]]=e1[i];
	}
	printf("\n sorted data=\n");
	for(i=0;i<n;i++)
	printf("\n%d     %s\n",e2[i].age,e2[i].name);
}
int main()
{
    FILE *fp1;
    int i,j;
    fp1=fopen("emp.txt","r");
    if(fp1==NULL)
    {
        printf("File Not Found......");
        exit(0);
    }
    i=0;
    while(!feof(fp1))
    {
        fscanf(fp1,"%d%s",&e1[i].age,&e1[i].name);
        i++;
    }
    j=i;
    fclose(fp1);
    for(i=0;i<j;i++)
    printf("\n%d     %s\n",e1[i].age,e1[i].name);
    count(e1,j);
}
