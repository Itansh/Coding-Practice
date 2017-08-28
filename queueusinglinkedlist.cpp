#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
typedef struct node Node;
Node *head=NULL;
int enqueue(int num)
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
		Node *tm=head;
		while(tm->next!=NULL)
		{
			tm=tm->next;
		}
		tm->next=x;
		x->next=NULL;
	}
}
int dequeue()
{
		if(head==NULL)
	{
		printf("\t\t\Queue empty \n");
	}
	else
	{
		head=head->next;
		printf("\t\t\tDequeue successfully \n");
	}
}
int main()
{
		int ch=1,en=0,num=0;
	while(ch)
	{
		printf("\n Enter your choice : \n");
		printf(" 1 : Enqueue \n");
		printf(" 2 : Dequeue \n");
		printf(" 3 : View Queue \n");
		printf(" 4 : Exit \n");	
		scanf("%d",&en);
		if(en==1)
		{
			printf("\t\t\tEnter value to be inserted :");
			scanf("%d",&num);
			enqueue(num);
			printf("\t\t\t%d inserted successfully \n",num);
		}
		if(en==2)
		{
			dequeue();	   
			
		}
		if(en==3)
		{   
			printf("\t\t\t");
			Node *tm=head;
			if(head==NULL)
			{
				printf("Queue empty \n");
			}
			else
			{
 				while(tm!=NULL)
				{	
					printf("<- %d ",tm->num);
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
}
