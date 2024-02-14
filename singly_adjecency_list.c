#include<stdio.h>
#include<malloc.h>
struct node{
    struct node *next;
    int data;
};
struct node *head[4];
void create(int a[10][10],int n)
{
    int i,j;
    struct node *newnode,*temp;
    for(i=1;i<=n;i++)
    {
        head[i]=NULL;
        for(j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                newnode=(struct node *)malloc(sizeof(struct node));
                newnode->data=j;
                newnode->next=NULL;
                if(head[i]==NULL)
                {
                    head[i]=temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}
void display(int n)
{
    struct node *temp;
    for(int i=1;i<=n;i++)
    {
        printf("\nV%d---->",i);
        for(temp=head[i];temp!=NULL;temp=temp->next)
        {
            printf("%d---->",temp->data);
        }
        printf("NULL");
    }
}
int main()
{
    int i,a[10][10],n,j;
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
    create(a,n);
    display(n);

}