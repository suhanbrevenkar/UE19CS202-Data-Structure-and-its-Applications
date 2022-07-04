#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	Node * the_node;
	Node * tracker;
	tracker=list->head;
	the_node=(Node *)malloc(sizeof(Node));
	the_node->data=data;
	the_node->link=NULL;
	if(list->head==NULL){
		list->head=the_node;
	}
	else{
		while(tracker->link!=NULL){
			tracker=tracker->link;
		}
		tracker->link=the_node;
	}
}
void list_delete_front(List* list) {
	if(list->head!=NULL){
		Node * dead_node;
		dead_node=list->head;
		list->head=dead_node->link;
		free(dead_node);
	}
}

void list_insert_at (List *list, int data, int position)
{
	int get_size(List * list){
		Node * tracker_node;
		tracker_node=list->head;
		int size=0;
		while(tracker_node!=NULL){
			size++;
			tracker_node=tracker_node->link;
		}
		return size;
	}
	void insert_at_front(List *list,int data){
		Node * the_node;
		Node * tracker_node;
		the_node=(Node *)malloc(sizeof(Node));
		the_node->data=data;
		the_node->link=NULL;
		if(list->head==NULL){
			list->head=the_node;
		}
		else{
			the_node->link=list->head;
			list->head=the_node;
		}
	}
	Node * the_node;
	Node * tracker_node;
	tracker_node=list->head;
	the_node=(Node *)malloc(sizeof(Node));
	the_node->data=data;
	the_node->link=NULL;
	int ctr=0;
	int size;
	size=get_size(list);
	if(list->head==NULL){
		list->head=the_node;
	}
	else{
		if(position==0){
			insert_at_front(list,data);
		}
		else if(position==size){
			insert_at_end(list,data);
		}
		else{
			while(ctr!=position-1){
				tracker_node=tracker_node->link;
				ctr++;
			}
			the_node->link=tracker_node->link;
			tracker_node->link=the_node;
		}
	} 
}

void list_reverse(List* list)
{
 	Node *current = list->head; 
    Node *prev=NULL;
	Node *next = NULL; 
	if(list->head!=NULL){
		while (current != NULL){
			next=current->link;
			current->link=prev;
			prev=current; 
			current=next; 
		} 
		list->head=prev;
	}
}


