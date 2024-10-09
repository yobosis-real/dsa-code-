#include<stdio.h>
#define MAX 10
int stack[10];
int top=-1;
void push(int item)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
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
		printf("stack underflow");
	else
	{
		elem = stack[top];
		top--;
		printf("%d is popped",elem);
	}
}

void display()
{	
	int i;
	if (top==-1)
	{
		printf("stck is empty\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}

void main()
{
	int ch=0,a;
	while(ch!=-1)
	{
	printf("select:-\n 1.pop\n 2.push\n 3.display\n-1.exit");
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
			scanf("%d",&a);
			push(a);
		}
		case 3:
		{
			
			display();
		}
	}
	printf("\n\n");
	}
}
