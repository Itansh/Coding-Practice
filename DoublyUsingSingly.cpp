#include<stdio.h>
#include<malloc.h>
#include <stdint.h>

struct node
{
	int data;
	struct node *ptr;
};
typedef struct node Node;

Node *head=NULL;

Node* XOR (Node *a,Node *b)
{
    return (Node*)((unsigned int)a ^ (unsigned int)b);
}

void insert(Node *root,int num)
{
	Node *tem=(Node*)malloc(sizeof(Node));
	tem->data=num;
	tem->ptr=NULL;
	if(head==NULL)
	{
		head=tem;
	}
	else
	{
		
	}
}
int main()
{
	Node *a=(Node*)malloc(sizeof(Node));
	a->data=5;
	a->ptr=NULL;
	
	Node *b=(Node*)malloc(sizeof(Node));
	b->data=6;
	a->ptr = XOR(a,b);
	b->ptr = XOR(a,b);
	
	Node *c=(Node*)malloc(sizeof(Node));
	c->data=7;
	c->ptr = XOR(b,XOR(c,a));
	b->ptr = XOR(b,XOR(c,a));
	
	Node *d=(Node*)malloc(sizeof(Node));
	d->data=8;
	d->ptr = XOR(c,XOR(d,b));
	d->ptr = XOR(c,XOR(d,b));
	
	Node *tem,*prev;
	tem=b;
	prev=a;
	printf("%d \n",tem->data);
	tem->ptr = XOR(tem->ptr ,prev->ptr);
	prev=tem;
	tem=tem->ptr;
 	printf("%d \n",tem->data);
 	tem->ptr = XOR(tem->ptr ,XOR(prev,tem));
	prev=tem;
	tem=tem->ptr;
 	printf("%d \n",tem->data);
 		
}
