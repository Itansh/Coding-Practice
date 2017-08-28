#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int num;
    struct node *left;
	struct node *right;
};
typedef struct node Node;
  
Node *create(int data)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->num=data;
    temp->left=NULL; 
	temp->right=NULL;
    return temp;
}
  
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("-> %d ", root->num);
        inorder(root->right);
    }
}
  
Node *insert(Node* x, int data)
{
    if (x==NULL) return create(data);
 	if (data < x->num)
        x->left  = insert(x->left, data);
    else 
	if (data > x->num)
        x->right = insert(x->right, data);   
 	return x;
}
  
int main()
{
	struct node *root = NULL;
	int ch=1,en=0,num=0;
	while(ch)
	{
		printf("\n Enter your choice : \n");
		printf("1 : Insert in BST \n");
		printf("2 : view inorder treversal \n");
		printf("3 : Exit \n");
		scanf("%d",&en);
		if(en==1)
		{
			printf("Enter value to be inserted :");
			scanf("%d",&num);
			root=insert(root,num);
			printf("%d inserted successfully \n",num);
		}
		if(en==2)
		{
			inorder(root);
		}
		if(en==3)
		{
			ch=0;
		}
	}
    return 0;
}
