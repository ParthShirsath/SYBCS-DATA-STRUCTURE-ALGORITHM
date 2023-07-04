#include<stdio.h>
#include<string.h>
struct student{
    int rno;
    char name[20];
    float per;
}s1[100],t;
int main()
{
    int pass,i,n;
    printf("Enter Limit=\n");
    scanf("%d",&n);
    printf("Enter N Student Information=\n");
    for(i=0;i<n;i++)
    {
        printf("Enter student Roll no,Name,Percentage");
        scanf("%d%s%f",&s1[i].rno,s1[i].name,&s1[i].per);
    }
    for(pass=1;pass<n;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(strcmp(s1[i].name,s1[i+1].name)>0)
            {
                t=s1[i];
                s1[i]=s1[i+1];
                s1[i+1]=t;
            }
        }
    }
    printf("Records In Names Sorted Order=\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%f\n",s1[i].rno,s1[i].name,s1[i].per);
    }
}
