#include<stdio.h>
int matrix[10][10],visited[10]={0},i,j,iteration,min,cost=0,u,v,n;
int main()
{
    printf("Enter Limit=");
    scanf("%d",&n);
    printf("Enter Adjecency Matrix=\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]==0)
            matrix[i][j]=999;
        }
    }

    for(iteration=1;iteration<=n;iteration++)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

                if(matrix[i][j]<min&&visited[j]==0)
                {
                    min=matrix[i][j];
                    u=i;
                    v=j;
                }
            }
        }
            if(visited[u]==0||visited[v]==0)
                {
                    printf("\nEdge %d : (%d---->%d) have %d cost",iteration,u,v,min);
                    cost+=min;
                    visited[v]=1;
                }
                matrix[u][v]=matrix[v][u]=999;
    }
    printf("\nFinal Minimum cost of Spanning tree=%d",cost);

}

/*
0 5 0 0 0 4
5 0 7 8 9 6
0 7 0 6 5 0
0 8 6 0 10 0
0 9 5 10 0 8
4 6 0 0 8 0 */