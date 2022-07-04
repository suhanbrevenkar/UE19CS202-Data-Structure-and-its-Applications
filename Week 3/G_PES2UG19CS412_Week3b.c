#include"dll.h"
int count_nodes(List* dll)
{
return dll->number_of_nodes;
}
void insert_front(List* dll, int data)
{
Node* fresh_node=(Node*)malloc(sizeof(Node));
fresh_node->data=data;
fresh_node->next=NULL;
fresh_node->prev=NULL;
Node *temp=dll->head;
if(dll->head==NULL || dll->tail==NULL)
{
dll->head=fresh_node;
dll->tail=fresh_node;
dll->number_of_nodes++;
return;
}
else
{
fresh_node->next=temp;
temp->prev=fresh_node;
dll->head=new_node;
dll->number_of_nodes++;   
}
}
void dllist_delete_beginning(List* list)
{
if(list->head==NULL)
{
return;
}
else
{
struct Node* del;
del=list->head;
list->head=list->head->next;
list->head->prev=NULL;
list->number_of_nodes--;
free(del);
}
}
void position_delete(List* dll, int pos)
{
Node *temp=dll->head;
Node *tempp=dll->tail;
if(dll->head==NULL || dll->tail==NULL)
{
return;
}
if(pos==0)
{
dllist_delete_beginning(dll);//function above
return;
}
if(pos>dll->number_of_nodes-1)
{
return;//out of bounds
}
if(pos<dll->number_of_nodes-1 && pos>0)
{
for (int i=0;i<pos-1;i++)
{//rest positions
temp=temp->next;
}
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
dll->number_of_nodes--;
}
else
{//last node
dll->tail=tempp->prev;
tempp->prev->next=NULL;
free(tempp);
dll->number_of_nodes--;
return;
}
}
int search_list(List* dll,int key)
{
if(dll->head==NULL)
{
return -2;
}
else
{
struct Node* find=dll->head;
int eleposi=0;
while(i<dll->number_of_nodes)
{
if(find->data==key)
{
return eleposi;
}
find=find->next;
eleposi++;
}
return -1;
}
}
void reverse_list(List* dll)
{
Node *present=dll->head;
Node *temp=NULL;
while(present!=NULL)
{
temp=present->prev;
present->prev=present->next;
present->next=temp;
present=present=present->prev;
}
dll->head=temp->prev;
while(temp->next!=NULL)
{
temp=temp->next;
}
dll->tail=temp;
}


