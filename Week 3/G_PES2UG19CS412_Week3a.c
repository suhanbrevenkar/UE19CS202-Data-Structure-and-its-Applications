#include "poly.h"
void insert_at_end(List *list, int data) 
{
Node* fresh_node=(Node*)malloc(sizeof(Node));
fresh_node->data=data;
fresh_node->link=NULL;
if(list->head==NULL)
{
list->head=fresh_node;
list->number_of_nodes++;
return;	
}
else
{
Node *temp=list->head;
while (temp->link!=NULL)
{
temp=temp->link;
}
temp->link=fresh_node;
list->number_of_nodes++;
}
}
long long int evaluate(List *list, int x)
{
int sum=0;
int power=1;
Node *temp=list->head;
while(temp!=NULL)
{
sum=sum+((temp->data)*power);
temp=temp->link;
power*=x;
}
return sum;
}
