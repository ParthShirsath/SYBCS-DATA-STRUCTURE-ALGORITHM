#include<stdio.h>
#include<ctype.h>
#define max 50

struct stack 
{
        char a[max];
        int top;
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

int isfull()
{
          if(s.top==max-1)
                    return 1;
          else
                   return 0;
}

void push(char c)
{
        if(isfull())
        printf("\n full ");
         else
         {
                  s.top++;
                  s.a[s.top]=c;
         }
}

char pop()
{       
          char ch;
          if(isempty())
          printf("\n empty");
          else
          {
          ch=s.a[s.top];
          s.top--;
          return ch;
          }
}

int pri(char x)
{
            if(x=='(')
              return 0;
            if(x=='+'||x=='-')
              return 1;
               if(x=='/'||x=='*')
              return 2;
                if(x=='$'||x=='^')
              return 3;
              return 0;
}

int main()
{
            char exp[50];
            char *e,x;
            
            printf("Enter infix Expression");
              scanf("%s",exp);
              e=exp;
              init();
              while (*e != '\0')
              {
                           if(isalnum(*e))
                               printf("%c",*e);
                           else if(*e == '(')
                           push(*e);
                           else if (*e == ')')
                           {
                                     while((x=pop()) != '(')
                                     printf("%c",x);
                           }
                           else 
                           {
                                 while(pri(s.a[s.top]) >= pri(*e))
                                        printf("%c",pop());
                                        push(*e);
                           }
                           e++;
              }
              while(!isempty())
              printf("%c",pop());
}