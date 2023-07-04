#include<stdio.h>
struct student{
    int rno;
    char sname[30];
    float per;
}s1[100],t;
int main()
{
    int n,i,pass;
    printf("enter Limit");
    scanf("%d",&n);
    printf("Enter Stduent Information=\n");
    for(i=0;i<n;i++)
    {
        printf("Enter Student Roll No,Name,Percentage");
        scanf("%d%s%f",&s1[i].rno,s1[i].sname,&s1[i].per);
    }
    for(pass=1;pass<n;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(s1[i].per>s1[i+1].per)
            {
                t=s1[i];
                s1[i]=s1[i+1];
                s1[i+1]=t;
            }
        }
    }
    printf("Records In Percentage order=\n");
    for(i=0;i<n;i++)
    printf("%d\t%s\t%.2f\n",s1[i].rno,s1[i].sname,s1[i].per);
}