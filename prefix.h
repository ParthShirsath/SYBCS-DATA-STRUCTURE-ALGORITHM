#define MAX 100
struct stack{
    char a[MAX];
    int top;
}s1;
void init()
{
    s1.top=-1;
}
int isempty()
{
    if(s1.top==-1)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(s1.top==MAX-1)
    return 1;
    else
    return 0;
}
void push(char c)
{
    if(isfull())
    {

    }
    else
    {
        s1.top++;
        s1.a[s1.top]=c;
    }
}
char pop()
{
    char ch;
    if(isempty())
    {

    }
    else
    {
        ch=s1.a[s1.top];
        s1.top--;
        return ch;
    }
}
int precedence(char c)
{
    if(c=='(')
    return 0;
    if(c=='+'||c=='-')
    return 1;
    if(c=='/'||c=='*')
    return 2;
    if(c=='$'||c=='^')
    return 3;
   return 0 ;
}