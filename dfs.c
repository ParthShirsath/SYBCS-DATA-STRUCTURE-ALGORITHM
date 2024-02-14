#include<stdio.h>
void dfs(int a[10][10],int i,int n)
{
    int j;
    static int visited[10]={0};
    visited[i]=1;
    printf("V%d----->",i);
        for(j=1;j<=n;j++)
            {
                if(a[i][j]==1&&visited[j]==0)
                {
                    dfs(a,j,n);
                }
            }
}
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
    printf("\n");
    dfs(a,1,n);
}