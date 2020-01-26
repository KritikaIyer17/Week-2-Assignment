#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data;
	struct node *next;
};
char x;
struct node* Create_Node(struct node *top,char ch)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=ch;
	p->next=NULL;
	return p;
}
struct node* push(struct node *top,char ch)
{
	struct node* p=Create_Node(top,ch);
	if(top==NULL)
	{
		top=p;
	}
	else
	{
		p->next=top;
		top=p;
	}
	return top;
}
struct node* pop(struct node *top)
{
	struct node *temp;
	temp=top;
	x=top->data;
	top=top->next;
	free(temp);
	return top;
}
int IsMatching(struct node *top, char ch[])
{	
	for(int i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='(')
		{
			top=push(top,ch[i]);
		}
		else
		{
			if(top==NULL)
			{
				return 0;
			}
			else
			{
				top=pop(top);
				if((x=='(')&&(ch[i]==')'))
				{
					;
				}
				else
				{	
					return 0;
				}
			}
		}
	}
	if(top==NULL)
	{
		return 1;
	}
	else
	{		
		return 0;
	}		
}
void main()
{
	struct node *top=NULL;
	int r;	
	char ch[50];
	printf("Enter an expression:\n");
	scanf("%s",ch);
	r=IsMatching(top,ch);
	if(r)
	{
		printf("Balanced!\n");	
	}
	else
	{
		printf("Not Balanced!\n");	
	}
}
