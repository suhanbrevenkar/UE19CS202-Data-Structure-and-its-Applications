#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
  //TODO
  Node* root = (Node*)malloc(sizeof(Node));
  root=NULL;
  tree->root=root;  
}

void tree_insert(Tree *tree, int data)
{
  // TODO : Insert element to create a BST
  Node *newnode,*temp;
	int flag=1;
	
	newnode=(Node *)(malloc(sizeof(Node)));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=data;
	
	if(tree->root==NULL)
    tree->root=newnode;
	else 
  {
    temp=tree->root;
	  while(flag)
		{
		if(data < temp->data)
		 {
      if(temp->left==NULL)
		   { 
          temp->left=newnode;
	        flag=0;
		   }
		  else 
        temp=temp->left;
		 }  
	  else 
     {
      if(temp->right==NULL)
		    { 
         temp->right=newnode;
			   flag=0;
			  }
			else temp=temp->right;
	   }
		}
	}
}
void tree_delete(Tree *tree, int element)
{
  // TODO : Delete elements from BST
  Node *temp,*q,*parent,*insucc;
	q=NULL;
	temp=tree->root;
	parent=NULL;
	
	while(temp!=NULL && temp->data!=element)
		{
			parent=temp;
			if(element<temp->data)
				temp=temp->left;
			else temp=temp->right;
		}
		
	if (temp==NULL)
    return;
  else if(temp->left==NULL)
    q=temp->right;
	else if(temp->right==NULL)
    q=temp->left;
	else 
  { 
		insucc=temp->right;
		while(insucc->left!=NULL)
			insucc=insucc->left;
		
		insucc->left = temp->left;
		q = temp->right;
		}
		
		
	if(parent==NULL)
    tree->root = q;
	else if(temp==parent->left)
    parent->left =q;
	else if(temp==parent->right)
    parent->right=q;
	free(temp);
}

void tree_inorder(Node *r)
{
  //TODO :  use printf to print inorder
  if(r!=NULL)
  {
    tree_inorder(r->left);
    printf("%d ",r->data);
    tree_inorder(r->right);
  }
}

void tree_preorder(Node *r)
{
  //TODO :  use printf to print preorder
  if(r!=NULL)
  {
    printf("%d ",r->data);
    tree_preorder(r->left);
    tree_preorder(r->right);
  }
}

void tree_postorder(Node *r)
{
  //TODO :  use printf to print postorder
  if(r!=NULL)
  {
    tree_postorder(r->left);
    tree_postorder(r->right);
    printf("%d ",r->data);
  }
}

void postorder(Tree *t)
{
  //TODO
  tree_postorder(t->root);
  printf("\n");
}

void preorder(Tree *t)
{
  //TODO
  tree_preorder(t->root);
  printf("\n");
}

void inorder(Tree *t)
{
  //TODO
  tree_inorder(t->root);
  printf("\n");   
}

void destroy(Node *r)
{
  //TODO
  destroy(r->left);
  destroy(r->right);
  free(r);  
}

void tree_destroy(Tree *t)
{ 
//TODO
  if(t->root==NULL)
    return;
  destroy(t->root);
}
/*
1 3
1 2
1 4
1 1
1 5
2
3
4
5 3
2
3
4
5 4
3
0

*/