#include<stdlib.h>
#include<stdio.h>
typedef struct node{
     struct node *left,*right;
     int data;
}NODE;
NODE *create(NODE *root)
{
    NODE *newnode,*temp,*parent;
     int i,n;
     printf("Enter Limit=");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         newnode=(NODE *)malloc(sizeof(NODE));
         newnode->left=NULL;
         newnode->right=NULL;
         printf("Enter Number=");
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
            if(temp->data<newnode->data)
            temp=temp->right;
            else
            temp=temp->left;
         }
         if(parent->data>newnode->data)
         parent->left=newnode;
         else
         parent->right=newnode;
     }
     return root;
}
void inorder(NODE *root)
{
    NODE *temp=root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
int compare(NODE *root1,NODE *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return 1;
    }
    else if(root1!=NULL && root2!=NULL)
    {
        if(root1->data==root2->data)
        {
            if(compare(root1->left,root2->left)&&compare(root1->right,root2->right))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    NODE *root1,*root2;
    printf("\nFirst Tree:-\n");
    root1=create(NULL);
    printf("\nSecond Tree:-\n");
    root2=create(NULL);
    printf("\n");
    printf("\nFirst Tree Data:-");
    inorder(root1);
    printf("\n\n");
    printf("\nSecond Tree Data:-");
    inorder(root2);
    if(compare(root1,root2))
    printf("\n\nTree is identical");
    else
    printf("\n\nTree Is Not identical");
}