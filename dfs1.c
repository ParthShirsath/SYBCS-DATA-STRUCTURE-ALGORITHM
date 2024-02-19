#include<stdio.h>
#define MAX 100
int visited[10]={0},b;
struct stack{
    int data[MAX],top;
}s;
void init()
{
    s.top=-1;
}
int isempty()
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}
int pop()
{
    int var;
    var=s.data[s.top];
    s.top--;
    return var;
}
void push(int vertex)
{
    s.top++;
    s.data[s.top]=vertex;
}
void dfs(int a[10][10],int i,int n)
{
    int j,vertex;
    visited[i]=1;
    if(i==1)
    {
        printf("\tV1---->");
        push(1);
    }
    while(!isempty())
    {
        vertex=pop();
            for(j=vertex;j<=n;j++)
            {
                if(a[i][j]==1 && visited[j]==0)
                {
                    push(j);
                    printf("V%d---->",j);
                    dfs(a,j,n);
                }
            }
    }
}
int main()
{
    int a[10][10],n,i,j;
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
    printf("Depth First Search Display=");
    dfs(a,1,n);
}

/*
0 1 0 1 0 1 0
0 0 1 0 1 0 0 
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0  
0 0 0 0 0 0 1
0 0 1 0 0 0 0 */