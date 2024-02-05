#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tree{
    struct tree *left,*right;
    int data;
}t1;
struct queue{
    struct tree *data1[MAX];
    int front,rear;
}q;
void init()
{
    q.front=q.rear=-1;
}
int isempty()
{
    if(q.rear==q.front)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(q.rear==MAX-1)
    return 1;
    else
    return 0;
}
void add(struct tree *num)
{
    q.data1[++q.rear]=num;
}
struct tree *delq()
{
    return q.data1[++q.front];
}
struct tree *create(struct tree *root)
{
    struct tree *newnode,*temp,*parent;
    int i,n;
    printf("Enter Limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct tree*)malloc(sizeof(struct tree));
        newnode->left=newnode->right=NULL;
        printf("Enter number=");
        scanf("%d",&newnode->data);
        if(root==NULL)
        {
            root=newnode;
            continue;
        }
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(temp->data>newnode->data)
            temp=temp->left;
            else
            temp=temp->right;
        }
        if(parent->data>newnode->data)
        parent->left=newnode;
        else
        parent->right=newnode;
    }
    return root;
}
void levelorder(struct tree *root)
{
    struct tree *temp,*M=NULL;
    init();
    int level=0;
    add(root);
    add(M);
    printf("\nLevel %d=",level);
    while(!isempty())
    {
        temp=delq();
        if(temp==M)
        {
            level++;
            if(!isempty())
            {
                add(M);
                printf("\nLevel %d=",level);
            }
        }
        else
        {
            printf("%d\t",temp->data);
            if(temp->left!=M)
            add(temp->left);
            if(temp->right!=M)
            add(temp->right);
        }
    }
}
void inorder(struct tree *root)
{
    struct tree *temp=root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
int main()
{
    struct tree *root=NULL;
    root=create(root);
    inorder(root);
    printf("\n");
    levelorder(root);
}