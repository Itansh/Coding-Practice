#include<stdio.h>
#include<conio.h>
#include<malloc.h>

using namespace std;
struct node
{
	int num;
	struct node *next;
};
typedef struct node Node;
Node *head=NULL;
void push(int num)
{
	Node *x=(Node*)malloc(sizeof(Node));
	x->num=num;
	if(head==NULL)
	{
		head=x;
		head->next=NULL;
	}
	else
	{
		x->next=head;
		head=x;
	}
}
void pop()
{
	if(head==NULL)
	{
		printf("\t\t\tStack empty \n");
	}
	else
	{
		head=head->next;
		printf("\t\t\tPop successfully \n");
	}
}
int main()
{
		int ch=1,en=0,num=0;
	while(ch)
	{
		printf("\n Enter your choice : \n");
		printf(" 1 : Push in Stack \n");
		printf(" 2 : Pop from stack \n");
		printf(" 3 : View stack \n");
		printf(" 4 : Exit \n");	
		scanf("%d",&en);
		if(en==1)
		{
			printf("\t\t\tEnter value to be inserted :");
			scanf("%d",&num);
			push(num);
			printf("\t\t\t%d inserted successfully \n",num);
		}
		if(en==2)
		{
			pop();	   
			
		}
		if(en==3)
		{   
//			printf("\t\t\t");
			Node *tm=head;
			if(head==NULL)
			{
				printf("\t\t\tStack empty \n");
			}
			else
			{
 				while(tm!=NULL)
				{	
					printf("\t\t\t|_ %d _|\n",tm->num);
					tm=tm->next;
				}
			}
		}
		if(en==4)
		{
			ch=0;
		}
	}
    return 0;
/*	push(12);
	push(45);
	push(56);
	Node *tm=head;
	while(tm!=NULL)
	{
		printf("-> %d",tm->num);
		tm=tm->next;
	}
	printf("\n");
	pop();
	pop();
	tm=head;
	while(tm!=NULL)
	{
		printf("-> %d",tm->num);
		tm=tm->next;
	}
	push(59);
	tm=head;
	printf("\n");
	while(tm!=NULL)
	{
		printf("-> %d",tm->num);
		tm=tm->next;
	}
*/
}

