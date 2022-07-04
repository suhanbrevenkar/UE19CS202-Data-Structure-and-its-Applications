#include "5a.h"

static Node* create_Node(int data, Node* link)
 {
	link->data=data;
	link->link=NULL;
	return link;
}


void list_initialize(List* ptr_list) 
{
	ptr_list->head=NULL;
	ptr_list->number_of_Nodes=0;
}


void list_insert_front(List* ptr_list, int data) 
{
	Node * node = (Node *)malloc(sizeof(Node));
	Node * new_node = create_Node(data,node);
	if(ptr_list->head==NULL){
		ptr_list->head=new_node;
	}
	else{
		new_node->link=ptr_list->head;
		ptr_list->head=new_node;
	}
	ptr_list->number_of_Nodes++;
}


const int Node_get_data(Node *Node_ptr) 
{
	return Node_ptr->data;
}


void list_delete_front(List* ptr_list) 
{
	Node * d_n;
	d_n=ptr_list->head;
	ptr_list->head=d_n->link;
	free(d_n);
	ptr_list->number_of_Nodes--;
}


void list_destroy(List* ptr_list) 
{
	Node * t_n;
	Node * d_n=NULL;
	t_n=ptr_list->head;
	while (t_n->link!=NULL){
		d_n=t_n;
		t_n=t_n->link;
		free(d_n);
	}
	free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
	ptr_Stack->ptr_list = (List *)malloc(sizeof(List));
	list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
	list_insert_front(ptr_Stack->ptr_list,key); 
}

void Stack_pop(Stack *ptr_Stack) 
{
	if(ptr_Stack->ptr_list->head!=NULL){
		list_delete_front(ptr_Stack->ptr_list);
	}
}

int Stack_is_empty(Stack *ptr_Stack) 
{
	if(ptr_Stack->ptr_list->number_of_Nodes!=0){
		return 0;
	}
	else{
		return 1;
	}
}

const int Stack_peek(Stack *ptr_Stack) 
{
	Node_get_data(ptr_Stack->ptr_list->head);
}

void Stack_destroy(Stack *ptr_Stack)
 {
	list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char* string)
{
	Stack *StackPointer = (Stack *)malloc(sizeof(Stack));
	Stack_initialize(StackPointer);
	int i = 0;
	while(string[i]!='\0'){
		if((string[i]==']' && Stack_is_empty(StackPointer)==1)||(string[i]==')' && Stack_is_empty(StackPointer)==1)||(string[i]=='}' && Stack_is_empty(StackPointer)==1)){ 
			Stack_push(StackPointer,string[i]);
		}
		else if(string[i]==']' && Stack_peek(StackPointer)=='['){
			Stack_pop(StackPointer);
		}
		else if(string[i]==')' && Stack_peek(StackPointer)=='('){
			Stack_pop(StackPointer);
		}
		else if(string[i]=='}' && Stack_peek(StackPointer)=='{'){
			Stack_pop(StackPointer);
		}
		else{ 
			Stack_push(StackPointer,string[i]);
		}
		i++;
	}
	return Stack_is_empty(StackPointer);
}	


 

