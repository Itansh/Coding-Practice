#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node *root=NULL;

void insertnode(int data)
{
	Node *ny=(Node *)malloc(sizeof(Node));
	ny->num=data;
	if(root==NULL)
	{
		root=ny;
		root->left=NULL;
		root->right=NULL;
		printf("Node Inserted \n");
		printf("%d",root->num);
	}
	else
	{
		Node *tem;
		tem=root;
		while(tem!=NULL)
		{
			if(data<tem->num)
			{
			tem=tem->left;
			}
			else
			{
			tem=tem->right;
			}
		}
		tem=ny;
		tem->left=NULL;
		tem->right=NULL;
		printf(" Node Inserted ");
		printf("%d \n" ,tem->num);
//		printf("%d \n",root->num);
	}
}

int max(int a,int b)
{
	if(a>b)
	 return a;
	else
	 return b;
}

int Height(Node *x)
{
	if(x==NULL)
	{
		return 0;
	}
	else
	{
		return 1+(max(Height(x->left),Height(x->right)));
	}
}



void Inordertreversal(Node *x)
{

	if(x==NULL)
		return;
		
	Inordertreversal(x->left);
	printf("-> %d",x->num);
	Inordertreversal(x->right);
		
}
int main()
{
	insertnode(7);
	insertnode(2);
	insertnode(3);
	insertnode(4);
	insertnode(5);
	Inordertreversal(root);
	printf("%d",root->left->num);
	getch();
	
}
