#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int c,e;
    struct node *next;
}NODE;
NODE *newnode,*temp1,*temp2,*temp3,*head,*temp;
#define MEMORY (NODE *)malloc(sizeof(NODE))
NODE *create(NODE *head)
{
    int i,n;
    printf("Enter Limit");
    scanf("%d",&n);
    printf("\nEnter Value Of The Exponent in descending order");
    for(i=0;i<n;i++)
    {
        newnode=MEMORY;
        newnode->next=NULL;
        printf("Enter Value Of Coefficient and exponent");
        scanf("%d%d",&newnode->c,&newnode->e);
        if(head==NULL)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
void disp(NODE *head)
{
    for(temp=head;temp->next!=NULL;temp=temp->next)
    printf("%dx^%d+",temp->c,temp->e);
    printf("%dx^%d",temp->c,temp->e);
}
NODE *insert(NODE *head,int res1,int res2)
{
        newnode=MEMORY;
        newnode->next=NULL;
        newnode->c=res1;
        newnode->e=res2;
        if(head==NULL)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    return head;
}
NODE *poly_mul(NODE *head1,NODE *head2)
{
	NODE *head3=NULL;
    int res1,res2;
    temp1=head1;
    temp2=head2;
    while(temp1!=NULL)
    {
    	temp2=head2;
        while(temp2!=NULL)
        {
            res1=temp1->c*temp2->c;
            res2=temp1->e+temp2->e;
            head3=insert(head3,res1,res2);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    printf("\n\n");
    disp(head3);
}
int main()
{
    NODE *head1=NULL,*head2=NULL;
    head1=create(head1);
    disp(head1);
    head2=create(head2);
    disp(head2);
	poly_mul(head1,head2);
}
