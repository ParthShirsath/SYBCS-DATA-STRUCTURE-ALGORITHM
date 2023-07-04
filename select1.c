#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,index;
    char min[20],t[20];
    char s1[20][20];
    printf("Enter Limit");
    scanf("%d",&n);
    printf("Enter N Names In an array=\n");
    for(i=0;i<n;i++)
    scanf("%s",s1[i]);
    for(i=0;i<n;i++)
    {
        
        strcpy(min,s1[i]);
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(s1[j],min)<0)
            {
                strcpy(min,s1[j]);
                index=j;
            }
        }
        strcpy(t,s1[i]);
        strcpy(s1[i],s1[index]);
        strcpy(s1[index],t);
    }
    printf("Names In Sorted Order=\n");
    for(i=0;i<n;i++)
    printf("%s\t",s1[i]);
}