#include<stdio.h>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct node
{
	int num;
	struct node *left;
	struct node *right;
};
typedef struct node Node;
Node *root=NULL;
int count=0;
Node *insert(Node *x,int data)
{
	if(x==NULL)
	{
		x=(Node*)malloc(sizeof(node));
		x->left=NULL;
		x->right=NULL;
		x->num=data;
		count++;
	}
	else
	if(data>x->num)
	{
		x->right=insert(x->right,data);
	}
	else
	{
		x->left=insert(x->right,data);
	}
	return(x);
}
void inorder(Node *x)
{
	if(x!=NULL)
	{
		printf("a");
		inorder(x->left);
		printf("-> %d\n",x->num);
		inorder(x->right);
	}
}
int main()
{
	root=insert(root,12);
	insert(root,15);
	insert(root,17);
	insert(root,11);
	inorder(root);
}
