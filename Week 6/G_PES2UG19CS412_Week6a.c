#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
	ptr_List->head=NULL;
	ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data) 
{
	Node * link = (Node *)malloc(sizeof(Node));
	Node * new_node = create_Node(data,link);
	if(ptr_List->head==NULL){
		ptr_List->head=new_node;
		ptr_List->number_of_Nodes+=1;
	}
	else{
		new_node->link=ptr_List->head;
		ptr_List->head=new_node;
		ptr_List->number_of_Nodes+=1;
	}
}

const int Node_get_data(Node *Node_ptr) 
{
	return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	if(ptr_List->head!=NULL){
		Node * dead_node;
		dead_node=ptr_List->head;
		ptr_List->head=dead_node->link;
		free(dead_node);
		ptr_List->number_of_Nodes-=1;
	}
}

void List_destroy(List* ptr_List) 
{
	Node * targeted_node;
	Node * dead_node=NULL;
	targeted_node=ptr_List->head;
	while (targeted_node->link!=NULL){
		dead_node=targeted_node;
		targeted_node=targeted_node->link;
		free(dead_node);
	}
	free(ptr_List);
}


void stack_initialize(Stack *ptr_stack) 
{
	ptr_stack->ptr_List = (List *)malloc(sizeof(List));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	List_insert_front(ptr_stack->ptr_List,key); 
}

void stack_pop(Stack *ptr_stack) 
{
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	if(ptr_stack->ptr_List->number_of_Nodes!=0){
		return 0;
	}
	else{
		return 1;
	}
}

const int stack_peek(Stack *ptr_stack)
{
	Node_get_data(ptr_stack->ptr_List->head);
}

void stack_destroy(Stack *ptr_stack) 
{
	List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression) 
{
	Stack *ptr_stack = (Stack *)malloc(sizeof(Stack));
	stack_initialize(ptr_stack);
	int i=0;
	int exp1;
	int exp2;
	int res;
	char op;
    while(expression[i]!='\0'){
		if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/'){
			op=expression[i];
			exp1=stack_peek(ptr_stack)-'0';
			stack_pop(ptr_stack);
			exp2=stack_peek(ptr_stack)-'0';
			stack_pop(ptr_stack);
			exp1=exp1-exp2;
			exp2=exp1+exp2;
			exp1=exp2-exp1;
			switch(op){
				case '+' : res=exp1+exp2;
						   break;	
				case '-' : res=exp1-exp2;
						   break;
				case '*' : res=exp1*exp2;
						   break;
				case '/' : res=exp1/exp2;
						   break;
			}
			stack_push(ptr_stack,res+'0');
		}
		else{
			stack_push(ptr_stack,expression[i]);
		}
		i+=1;
	}
	return stack_peek(ptr_stack)-'0';
}
