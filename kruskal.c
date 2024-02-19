#include<stdio.h>
int parent[15];
int check(int u,int v)
{
    if(u!=v)
    {
        parent[v]=u;
        return 1;
    }
    return 0;
}
int find(int i)
{
    while(parent[i])
    i=parent[i];
    return i;
}
int main()
{
    int ab[10][10],i,j,n;
    printf("Enter Number of vertices=");
    scanf("%d",&n);
    printf("Enter costr Adjecency Matrix=");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&ab[i][j]);
            if(ab[i][j]==0)
            ab[i][j]=999;
        }
    }
    int a,b,u,v,min,cost=0,iteration;
    for(iteration=1;iteration<12;iteration++)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(ab[i][j]<min)
                {
                    min=ab[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(check(u,v)==1)
        {
            printf("\nEdge %d :(%d--->%d)cost=%d",iteration,a,b,min);
            cost+=min;
        }
        ab[a][b]=ab[b][a]=999;
    }
    printf("\nMinimum Cost Spanning Tree minimum cost=%d",cost);
}
/*
0 4 0 0 0 0 5
4 0 8 0 0 0 7
0 8 0 10 13 0 6
0 0 10 0 11 0 0 
0 0 13 11 0 4 7
0 0 0 0 4 0 5
5 7 6 0 7 5 0 */