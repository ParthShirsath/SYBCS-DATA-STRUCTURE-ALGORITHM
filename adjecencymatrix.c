#include<stdio.h>
int main()
{
    int a[10][10],i,j,n;
    printf("Enter Number of Vertex=");
    scanf("%d",&n);
    printf("Enter The Matrix=");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    printf("\tV%d",i);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("V%d\t",i);
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
}