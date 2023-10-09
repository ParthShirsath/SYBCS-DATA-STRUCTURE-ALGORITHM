#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#define MEMORY (struct node *)malloc(sizeof(struct node))
typedef struct node{
    int data;
    struct node *next,*prev;
}NODE;
NODE *create(NODE *head)
{
    NODE *newnode,*temp;
    int n,i;
     printf("Enter limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=MEMORY;
        newnode->next=newnode->prev=NULL;
        printf("enter number");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=newnode;
            temp=newnode;
        }
    }
    return head;
}
void disp(NODE *head)
{
    NODE *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d    ",temp->data);
    }
}
NODE *bubblesort(NODE *head)
{
    NODE *i,*pass,*temp;
    for(pass=head;pass!=NULL;pass=pass->next)
    {
        for(i=head;i!=pass;i=i->next)
        {
            if((pass->data)<(i->data))
            {
                temp=pass->data;
                pass->data=i->data;
                i->data=temp;
            }
        }
    }
    return head;
}
int main()
{
    NODE *head=NULL;
    head=create(head);
    disp(head);
    printf("\n\n");
    head=bubblesort(head);
    disp(head);
}