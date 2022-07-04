#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    tree=(Tree *)malloc(sizeof(Tree));
	tree->root=NULL;
	return;
}

void tree_insert(Tree *tree, int data)
{
    int a=1;
    Node *tree_r=tree->root;
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    temp->rightThread=temp->leftThread=1;

    if(tree_r==NULL)
        tree->root=temp;

    Node *tree_rt;
    tree_rt=tree->root;

    while(1)
    {
        if(data<tree_rt->data)
        {
            if(tree_rt->leftThread==0)
                tree_rt=tree_rt->left;
            else
                break;
        }

        else
        {
            if(tree_rt->rightThread==0)
                tree_rt=tree_rt->right;

            else
                break;
        }
    }

    if(data<tree_rt->data)
    {
        temp->left=tree_rt->left;
        tree_rt->left=temp;
        tree_rt->leftThread=0;
        temp->right=tree_rt;
    }

    else if(data>tree_rt->data)
    {
        temp->right=tree_rt->right;
        tree_rt->right=temp;
        tree_rt->rightThread=0;
        temp->left=tree_rt;
    }
}

Node *inorder_predecessor(Node *ptr)
{
    if(ptr->leftThread==1)
        return ptr=ptr->left;

    ptr=ptr->left;

    while(ptr->rightThread==0)
        ptr=ptr->right;

    return ptr;
}

Node *inorder_successor(Node *ptr)
{
    if(ptr->rightThread==1)
        return ptr=ptr->right;

    ptr=ptr->right;

    while(ptr->leftThread==0)
        ptr=ptr->left;

    return ptr;
}

void print_ascending(Tree *tree)
{
    Node *temp;

    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }

    temp=tree->root;
    while(temp->leftThread==0)
    {
        temp=temp->left;
    }

    while(temp!=NULL)
    {
        printfun(temp->data);
        temp=inorder_successor(temp);
    }

    nextline();
}

void print_descending(Tree *tree)
{
    Node *temp;

    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }

    temp=tree->root;
    while(temp->rightThread==0)
    {
        temp=temp->right;
    }

    while(temp!=NULL)
    {
        printfun(temp->data);
        temp=inorder_predecessor(temp);
    }

    nextline();
}

void destroy(Node *r)
{
    //TODO
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
