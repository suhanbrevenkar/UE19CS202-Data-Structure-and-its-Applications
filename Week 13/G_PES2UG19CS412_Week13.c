#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
  {
    typedef struct trienode Trie;
	Trie * trie = (Trie *)malloc(sizeof(Trie)); 
	trie->endofword = 0;
	for(int i=0; i<26; i++){
		trie->child[i] = NULL;
	}
	return trie;
  }

  void insert(struct trienode *root, char *key)
  {
	struct trienode * root_tracker;
	root_tracker = root;
	if(root_tracker==NULL){
		root_tracker = getnode();
	}
	for(int i=0;i<100;i++){
		if(key[i]=='\0'){
			break;
		}
		else{
			if(root_tracker->child[key[i]-'a']==NULL){
				struct trienode * character_node;
				character_node=getnode();
				root_tracker->child[key[i]-'a']=character_node;
			}
			root_tracker=root_tracker->child[key[i]-'a'];
		}
	}
	if(root_tracker -> endofword != 0){
		return;
	}
	root_tracker->endofword=1;
  }
void display(struct trienode *curr)
  {
      for(int i=0; i<26; i++){
		  if(curr->child[i]!=NULL){
			  word[length] = (i+'a');
			  length++;
			  if(curr->child[i]->endofword==1){
				  for(int j=0; j<length; j++){
					  printfun(j+'a');
				  }
				  printf("\n");
			  }
			display(curr->child[i]);
		  }
	  }
	  return;
 }

  int search(struct trienode * root,char *key)
  {
	int i=0;
	struct trienode * root_tracker;
	root_tracker = root;
	while(key[i]!='\0'){
		if(root_tracker->child[key[i]-'a']==NULL){
			return 0;
		}
		root_tracker=root_tracker->child[key[i]-'a'];
		i++;
	}
	if(root_tracker->endofword==1){
		return 1;
	}
  }


 void delete_trie(struct trienode *root,char *key)
  {
	int index;
    struct trienode* root_tracker;
    root_tracker=root;

    for(int i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(root_tracker->child[index]==NULL)
      {
         return;
      }
      root_tracker=root_tracker->child[index];
    }
      root_tracker->endofword=0;
      return;
  }

  int check(struct trienode *x)
  {
    //TODO
 }

  void push(struct trienode *x,int k)
  {
    //TODO
  } 

  struct stack pop()
  {
    //TODO
  }























 /*void display(struct trienode *curr)
 {
   int i,j;
   for(i=0;i<26;i++)
   {
     if(curr->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(curr->child[i]->endofword==1)//if word found
       {
          printf("\n");//print the word
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(curr->child[i]);
     }
    }
    length--;
    return;
 }



 struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }


 void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        curr->child[index]=getnode();
      curr=curr->child[index];
    }
    curr->endofword=1;
  }


 int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
  }

 void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* curr;
    curr=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      curr=curr->child[index];
    }
      curr->endofword=0;
      return;
  }*/













 


 
 



















