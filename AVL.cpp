#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int num,height,index;
    struct node *left;
	struct node *right;
};
typedef struct node Node;
int arr[15]={00};
int a=0;
Node *create(int data)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->num=data;
    temp->left=NULL; 
	temp->right=NULL;
	temp->height=1;
    return temp;
}
int assignindex(Node *x,int n)
{
	if(x!=NULL)
	{
	x->index=n;
//	printf(" \n %d",x->index);
	assignindex(x->left,((2*n)+1));
	assignindex(x->right,((2*n)+2));
	}
	else
	{
		return 0;
	}

}
void display(Node *x)
{
	
	printf("\t\t          %d           \n",arr[0]);
	printf("\t\t        /   \\          \n");
	printf("\t\t      %d        %d     \n",arr[1],arr[2]);
	printf("\t\t    /   \\      /  \\    \n");
	printf("\t\t  %d    %d     %d   %d \n",arr[3],arr[4],arr[5],arr[6]);
	printf("\t\t / \\   / \\    / \\  / \\ \n");
	printf("\t\t%d  %d %d  %d   %d  %d %d  %d\n",arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14]);

}
int max(int a,int b)
{
	if(a>b)
	 return a;
	else
	 return b;
}

int height(Node *x)
{
	if(x==NULL)
	{
		return 0;
	}
	else
	{
		return 1+(max(height(x->left),height(x->right)));
	}
}
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        root->height=1+max(height(root->left),height(root->right));
   	    arr[root->index]=root->num;
        inorder(root->right);
    }
}
 
Node *rotateright(Node* root)
{

	Node *newroot=root->left;
	Node *tem=newroot->right;
	
	newroot->right=root;
	root->left=tem;
	
	root->height=max(height(root->left),height(root->right))+1;
	newroot->height=max(height(newroot->left),height(newroot->right))+1;
	return newroot;
}  

Node *rotateleft(Node* root)
{
	Node *newroot=root->right;
	Node *tem=newroot->left;
	
	newroot->left=root;
	root->right=tem;
	
	root->height=max(height(root->left),height(root->right))+1;
	newroot->height=max(height(newroot->left),height(newroot->right))+1;
	return newroot;
}

  
int getbalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *avlinsert(Node* root,int data)
{
	if(root==NULL)
	{
		printf("inserting...%d \n",data);
		return create(data);
	}
 if (data < root->num)
        root->left  = avlinsert(root->left, data);
    else if (data > root->num)
        root->right = avlinsert(root->right, data);	
    
	int balance=getbalance(root);
	
	  root->height = 1 + max(height(root->left),height(root->right));
	if(balance>1)
	{
		if(height(root->left->left)>=height(root->left->right))
		{
			return rotateright(root);
		}
		else
		{
			root->left=rotateleft(root->left);
			return rotateright(root);
		}
	}
	if(balance <-1)
	{
		if(height(root->right->right)>=height(root->right->left))
		{
			
			return rotateleft(root);
		}
		else
		{
			root->right=rotateright(root->right);
			return rotateleft(root);
		}
	}
/*
	if (balance > 1 && data < root->left->num)
        return rotateright(root);
 
    // Right Right Case
    if (balance < -1 && data > root->right->num)
        return rotateleft(root);
 
    // Left Right Case
    if (balance > 1 && data > root->left->num)
    {
        root->left =  rotateleft(root->left);
        return rotateright(root);
    }
 
    // Right Left Case
    if (balance < -1 && data < root->right->num)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
*/
	root->height=1+max(height(root->left),height(root->right));
	return root;
	
}  

void preorder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d \n", root->num);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
	struct node *root = NULL;
	int ch=1,en=0,num=0;
	while(ch)
	{
		printf("\n Enter your choice : \n");
		printf(" 1 : Insert in AVL \n");
		printf(" 2 : view tree \n");
		printf(" 3 : Exit \n");
		scanf("%d",&en);
		if(en==1)
		{
			printf("Enter value to be inserted :");
			scanf("%d",&num);
			root=avlinsert(root,num);
			    printf("...\n");
    			assignindex(root,0);
    			inorder(root);
    			display(root);
			printf("%d inserted successfully \n",num);
		}
		if(en==2)
		{
			    printf("...\n");
    			assignindex(root,0);
    			inorder(root);
    			display(root);
		}
		if(en==3)
		{
			ch=0;
		}
	}
    return 0;

}
