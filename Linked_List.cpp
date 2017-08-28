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
void printList(void);
void insertinfront(int data)
{
	Node *ny=(Node *)malloc(sizeof(Node));
	ny->num=data;
	ny->next=head;
	head=ny; 
	printList();		
}

void insertinend(int data)
{
	Node *ny=(Node *)malloc(sizeof(Node));
	ny->num=data;
	Node *tem;
	tem=head;
	while(tem->next!=NULL)
	{
		tem=tem->next;
	}
	tem->next=ny;
	ny->next=NULL;
	printList();
}
void erase()
{
	head=head->next;
}

void printList()
{
	Node *ptr=head;
	while(ptr != NULL)
	{
		printf("->%d ",ptr->num);
		ptr=ptr->next;
	}
	printf("\n");
}

bool isEmpty()
{
	return head==NULL;
}

int length()
{
	int len=0;
	Node *tem;
	for(tem=head; tem!=NULL ;tem->next)
	{
		len++;
	}
	return len;
}

void dump(int data)
{
	Node *current=head;
	Node *prev=NULL;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(current->num!=data)
		{
			if(current->next==NULL)
			{
				printf("data not found");
				break;
			}
			else
			{
				prev=current;
				current=current->next;
			}
		}
		if(current==head)
		{
			head=head->next;
		}
		else
		{
			prev->next=current->next;
		}
	}
	printList();
} 

int main()
{
	int ch=1,en=0,num=0;
	while(ch)
	{
		printf("Enter your choice : \n");
		printf("1 - Insert in front \n");
		printf("2 - Insert in end \n");
		printf("3 - Print List \n");
		printf("4 - Delete from list \n");
		printf("5 - Exit \n");
		scanf("%d",&en);
		if(en==1)
		{
			printf("Enter number to insert in front : ");
			scanf("%d",&num);
			insertinfront(num);	
		}
		if(en==2)
		{
			printf("Enter number to insert in end : ");
			scanf("%d",&num);
			insertinend(num);
		}
		if(en==3)
		{
			printList();
		}
		if(en==4)
		{
			printf("Enter number to delete : ");
			scanf("%d",&num);
			dump(num);
		}
		if(en==5)
		{
			ch=0;
		}
	}

}



