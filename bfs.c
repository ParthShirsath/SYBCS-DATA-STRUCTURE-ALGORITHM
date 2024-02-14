#include<stdio.h>
#define MAX 100
struct queue{
    int front,rear,data[MAX];
}q;
void init()
{
    q.front=q.rear=0;
}
void add(int data1)
{
    q.data[++q.rear]=data1;
}
int removeq()
{
    return q.data[++q.front];
}
int isempty()
{
    if(q.front==q.rear)
    return 1;
    else
    return 0;
}
void bfs(int a[10][10],int n)
{
    int visited[10]={0};
    init();
    int i=1,j;
    int vertex;
    visited[i]=1;
    add(i);
    while(!isempty())
    {
        vertex=removeq();
        printf("%d\t",vertex);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]==1&&visited[j]==0)
                {
                    add(j);
                    visited[j]=1;
                }
            }
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
    printf("Breadth First Search Display=");
    bfs(a,n);
}