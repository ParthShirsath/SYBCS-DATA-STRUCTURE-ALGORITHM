#include<stdio.h>
#include<stdlib.h>
struct node{
     struct node *left,*right;
     int data;
};
struct node *create(struct node *root)
{
	struct node *parent,*newnode,*temp;
	int i,n;
	printf("Enter limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter value=");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
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
void inorder(struct node *root)
{
        struct node *temp=root;
        if(temp!=NULL)
        {
        	inorder(temp->left);
        	printf("%d\t",temp->data);
        	inorder(temp->right);
        }
}
void preorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
int main()
{
	struct node *root=NULL;
	root=create(root);
	printf("\nInorder Display=\n");
	inorder(root);
	printf("\nPreorder Display=\n");
	preorder(root);
	printf("\nPostorder Display=\n");
	postorder(root);
}
