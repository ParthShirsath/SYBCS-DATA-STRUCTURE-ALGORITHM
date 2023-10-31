#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *newnode,*temp,*list,*temp1;

Node * create(Node *list,int num)
{
    newnode=(Node *)malloc(sizeof(Node));
    newnode->data=num;
    newnode->next=NULL;
    if(list==NULL||num<list->data)
    {
    newnode->next=list;
	list=newnode;
    }
    else
    {
	temp1=list;
	while(temp1->next!=NULL&&num>temp1->next->data)
	{
		temp1=temp1->next;
	}
		
		newnode->next=temp1->next;
		temp1->next=newnode;
    }
    return list;
}
void display(Node *list) 
{
    Node* temp = list;
    while (temp != NULL) 
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int main()
{
int n,num,i;
list=NULL;
printf("Enter Limit");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Number");
scanf("%d",&num);
list=create(list,num);
}
display(list);
}