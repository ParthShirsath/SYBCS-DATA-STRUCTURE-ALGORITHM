#include<stdio.h>
struct Student{
    int rno;
    char sname[20];
    float per;
}s1[100];
int main()
{
    int top,mid,bottom,n,i,no,flag=0;
    printf("Enter Limit");
    scanf("%d",&n);
    printf("Enter Student Roll_no,name,percentage=\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%s%f",&s1[i].rno,s1[i].sname,&s1[i].per);
    }
    printf("enter Student Roll no to Search record=");
    scanf("%d",&no);
    top=0;
    bottom=n-1;
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(s1[mid].rno==no)
        {
            flag=1;
            break;
        }
        if(no>s1[mid].rno)
        top=mid+1;
        else
        bottom=mid-1;
    }
    if(flag==1)
    printf("\nStudent Roll_no=%d,name=%s,percentage=%f",s1[mid].rno,s1[mid].sname,s1[mid].per);
    else
    printf("Record Not Found......!");
}
