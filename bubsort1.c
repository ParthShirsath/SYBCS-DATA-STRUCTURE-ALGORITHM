#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,pass;
    char s1[30][30],t[30];
    printf("enter Limit");
    scanf("%d",&n);
    printf("Enter N Names in An Array");
    for(i=0;i<n;i++)
    {
        scanf("%s",&s1[i]);
    }
    for(pass=1;pass<n;pass++)
    {
        for(i=0;i<n-pass;i++)
        {
            if(strcmp(s1[i],s1[i+1])>0)
            {
                strcpy(t,s1[i]);
                strcpy(s1[i],s1[i+1]);
                strcpy(s1[i+1],t);
            }
        }
    }
    printf("NAmes In Sorted Order=\n");
    for(i=0;i<n;i++)
    printf("%s\t",s1[i]);    
}