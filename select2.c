#include<stdio.h>
struct student{
    int rno;
    char name[30];
    float per;
}s1[10],t;
int main()
{
    int n,i,j,max,index;
    printf("Enter Limit");
    scanf("%d",&n);
    printf("Enter N Record=\n");
    for(i=0;i<n;i++)
    scanf("%d%s%f",&s1[i].rno,s1[i].name,&s1[i].per);
    for(i=0;i<n;i++)
    {
        max=s1[i].per;
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(s1[j].per>max)
            {
                max=s1[j].per;
                index=j;
            }
        }
        t=s1[i];
        s1[i]=s1[index];
        s1[index]=t;
    }
    printf("Records In Sorted Order=\n");
    for(i=0;i<n;i++)
    printf("%d\t%s\t%f\n",s1[i].rno,s1[i].name,s1[i].per);
}