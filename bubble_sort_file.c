#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct emp{
    char ename[20];
    int salary;
}e1[100],t;
void bubble(struct emp e1[100],int n)
{
    int pass,i;
    for(pass=1;pass<n;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(e1[i].salary>e1[i+1].salary)
            {
                t=e1[i];
                e1[i]=e1[i+1];
                e1[i+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s   %d\n",e1[i].ename,e1[i].salary);
    }
}
int main()
{
    FILE *fp1;
    fp1=fopen("emp.txt","r");
    if(fp1==NULL)
    {
        printf("File Is Empty");
        exit(0);
    }
    int i=0;
    while(!feof(fp1))
    {
        fscanf(fp1,"%s%d",&e1[i].ename,&e1[i].salary);
        i++;
    }
    int j=i-1;
    fclose(fp1);
    bubble(e1,j);
}
