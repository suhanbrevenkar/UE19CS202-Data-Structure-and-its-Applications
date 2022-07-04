#include "et.h"

Node * createExpressionTree(char* a,int len)
{
	Node *new,*cur,*temp,*root=NULL;
  	char *b=a+(len-1);

  	for(int i=len-1;i>=0;i--)
  	{
    	new=(Node*)malloc(sizeof(Node));
    	new->data=*b;
    	new->left=NULL;
		new->right=NULL;
		new->prev=NULL;

    	if(root==NULL)
    	{
       		root=new;
       		cur=temp=root;
    	}

    	else
    	{
    		if(*b=='+'||*b=='-'||*b=='*'||*b=='/')
      		{
       			if(temp->right==NULL)
             	{
                	cur=new;
                	temp->right=cur;
                	cur->prev=temp;
                	temp=cur;
             	}

       			else if(temp->left==NULL)
             	{
                	cur=new;
                	temp->left=cur;
                	cur->prev=temp;
                	temp=cur;
             	}

       			else
             	{
               		while(temp->left!=NULL)
               		{
                    	temp=temp->prev;
               		}
               		cur=new;
               		temp->left=cur;
               		cur->prev=temp;
               		temp=cur;
             		}
      			}

      			else
      			{
        			if(temp->right==NULL)
             		{
                		cur=new;
                		temp->right=cur;
                		cur->prev=temp;
            		}

        			else if(temp->left==NULL)
             		{
                		cur=new;
                		temp->left=cur;
                		cur->prev=temp;
             		}

         			else
             		{
                 		while(temp->left!=NULL)
                 		{
                     		temp=temp->prev;
                 		}
                 		cur=new;
                 		temp->left=cur;
                 		cur->prev=temp;
            		}
     			}
    	}
    	b--;
  	}
  	return root;
}


void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%c",root->data);
		inorder(root->right);
	}
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
  		printf("%c",root->data);
		preorder(root->left);
		preorder(root->right);
	} 
}

void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
  		printf("%c",root->data);
	}
}

void freeTree(Node *root)
{
	if(root==NULL)
		return;

	if(root->left==NULL && root->right==NULL)
	{
		free(root);
		return;
	}

	if(root->left!=NULL)
		freeTree(root->left);
	
	if(root->right!=NULL)
		freeTree(root->right);
}


