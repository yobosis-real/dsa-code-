#include<stdio.h>
#define MAX 10
char stack[10];
int top=-1;

char checkbal(char symbol)
{
      char popped;
      if((stack[top]=='(' && symbol==')')||(stack[top]=='[' && symbol==']')||(stack[top]=='{' && symbol=='}'))
      {
            popped=stack[top];
            top=top-1;
            return popped;
      }
      else 
      {
            return '0';
      }
}
void push(char item)
{
	if(top==MAX-1)
	{
		printf("stack overflow.\n");
	}
	else
	{
		top++;		
		stack[top]=item;
	}
}

void pop()
{	
	int elem;
	if(top==-1)
		printf("stack underflow.");
	else
	{
		elem = stack[top];
		top--;
		printf("%d is popped.",elem);
	}
}

void display()
{	
	int i;
	if (top==-1)
	{
		printf("stack is empty.\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%c\n",stack[i]);
		}
	}
}

void main()
{
	int ch=0,i;
	char a,sym,exp[10];
	while(ch!=5)
	{
	printf("select:-\n   1.pop\n   2.push\n   3.display\n   4.check balance\n   5.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			pop();
			break;
		}
		case 2:
		{
			printf("\nenter element to push : ");
			scanf("%c ",&a);
			push(a);
			break;
		}
		case 3:
		{
			
			display();
			break;
		}
		case 4:
		{
		      printf("enter a expression with parathesis. \n");
		      scanf("%s",exp);
		      for(i=0;exp[i]!='\0';i++)
		      {
		            if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		                  push(exp[i]);
		            else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		            {
		                  sym=checkbal(exp[i]);
		                  if(sym=='0')
		                        break;
		            }
		      }
		      if(top==-1 && sym!='0')
		            printf("paranthesis are balanced\n");
		      else
		            printf("paranthesis are not balanced\n");
		      break;
		}
	}
	printf("\n\n\n");
	}
}
