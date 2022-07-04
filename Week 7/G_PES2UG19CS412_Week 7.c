#include "queue.h"
static node *create_node(int id, int time, node *link)
{
	node * generated_node=(node *)malloc(sizeof(node));
	generated_node->id=id;
	generated_node->time=time;
	generated_node->link=NULL;
	return generated_node;
}
void list_initialize(List *ptr_list)
{
	ptr_list->head=NULL;
	ptr_list->tail=NULL;
	ptr_list->number_of_nodes=0;
}
const int node_get_id(node *node_ptr)
{
	return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
	return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode = create_node(id,time,newnode);
	node * tail_tracker;
	tail_tracker=ptr_list->tail;
	if(ptr_list->head==NULL && ptr_list->tail==NULL){
		
		ptr_list->head=ptr_list->tail=newnode;
	}
	else{
		
		tail_tracker->link=newnode;
		ptr_list->tail=newnode;
	}
	ptr_list->number_of_nodes+=1;
	
}

void list_delete_front(List *ptr_list)
{
	if(ptr_list->head != NULL && ptr_list->tail != NULL){
		node * dead_node;
		dead_node=ptr_list->head;
		ptr_list->head=dead_node->link;
		free(dead_node);
		ptr_list->number_of_nodes-=1;
		if(ptr_list->number_of_nodes==0){
			list_initialize(ptr_list);
		}
	}
	
}

void list_destroy(List *ptr_list)
{
	node *targeted_node, *dying_node=NULL;
	targeted_node=ptr_list->head;
	while (targeted_node != NULL){
		dying_node=targeted_node;
		targeted_node=targeted_node->link;
		free(dying_node);
	}
	free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
	queue_list->ptr_list = (List *)malloc(sizeof(List));
	list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
	list_insert_rear(ptr->ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
	list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
	if(ptr->ptr_list->number_of_nodes==0){
		return 0;
	}
	else{
		return 1;
	}
}

void queue_peek(Queue *ptr)
{
	if(queue_is_empty(ptr)!=0){
		int id = ptr->ptr_list->head->id;
		int time = ptr->ptr_list->head->time;
		printf("%d %d\n",id,time);
	}
	else{
		printf("EMPTY QUEUE\n");
	}
}

void queue_destroy(Queue *ptr)
{
	list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
	
	void list_delete_end(List* list){
		node * dead_node;
		node * head_tracker;
		node * prev_tracker;
		prev_tracker=ptr_queue->ptr_list->head;
		head_tracker=prev_tracker->link;
		dead_node=head_tracker->link;
		while(dead_node!=NULL){
			prev_tracker=prev_tracker->link;
			head_tracker=head_tracker->link;
			dead_node=dead_node->link;
		}
		
		head_tracker=dead_node;
		ptr_queue->ptr_list->tail=prev_tracker;
		ptr_queue->ptr_list->tail->link=NULL;
		
		free(dead_node);
		ptr_queue->ptr_list->number_of_nodes-=1;
		
	}
	void list_delete_midway(List* list, node * prev_node,node * dead_node,node * forw_node){
		if(dead_node==ptr_queue->ptr_list->tail){
			list_delete_end(ptr_queue->ptr_list);
		}
		else{
			prev_node->link=forw_node;
			free(dead_node);
			ptr_queue->ptr_list->number_of_nodes-=1;
			if(ptr_queue->ptr_list->number_of_nodes==0){
				list_initialize(ptr_queue->ptr_list);
			}
			
		}
	}
	if(ptr_queue->ptr_list->number_of_nodes!=0){
	node * head_tracker;
	node * head_tracker2;
	node * tail_tracker;
	head_tracker=ptr_queue->ptr_list->head;
	
	head_tracker2=head_tracker;
	tail_tracker=ptr_queue->ptr_list->tail;
	int totalsum=0;
	while(head_tracker2!=NULL){
		totalsum+=head_tracker2->time;
		head_tracker2=head_tracker2->link;
	}
	
	int sum=node_get_time(head_tracker);
	if(ptr_queue->ptr_list->number_of_nodes!=0){
		if(t>=0 && t<=node_get_time(head_tracker)){
			printf("%d\n",node_get_id(head_tracker));
			queue_dequeue(ptr_queue);
		}
		else if(t>node_get_time(head_tracker) && t<totalsum){
			
			while(head_tracker!=NULL){
				
				
				
				if(t>sum && t<=(sum+head_tracker->link->time)){
					printf("%d\n",node_get_id(head_tracker->link));
					list_delete_midway(ptr_queue->ptr_list,head_tracker,head_tracker->link,head_tracker->link->link);
					break;
				}
				
				sum+=head_tracker->link->time;
				
				head_tracker=head_tracker->link;
			}
		}
		else if(t==totalsum){
			printf("%d\n",node_get_id(tail_tracker));
			list_delete_end(ptr_queue->ptr_list);
		}
	}
	}
	else{
		printf("EMPTY QUEUE\n");
	}
}




