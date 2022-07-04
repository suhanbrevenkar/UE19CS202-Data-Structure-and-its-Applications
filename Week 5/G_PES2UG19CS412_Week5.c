#include "5a.h"

static Node* create_Node(int data, Node* link)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->link = link;
  node->data = data;
  return node;
}


void list_initialize(struct List* ptr_list)
{

   ptr_list->head=NULL;
   ptr_list->number_of_Nodes=0;
}


void list_insert_front (struct List* ptr_list, int data)
{
  struct Node* pt;
  pt= ptr_list->head;
  struct Node* temp = create_Node(data,pt);
  ptr_list->head = temp;
  ptr_list->number_of_Nodes++;
}
const int Node_get_data(Node *Node_ptr)
{


   return (Node_ptr->data);
}


void list_delete_front (struct List* ptr_list)
{
    Node * temp = ptr_list->head;
    ptr_list->head=ptr_list->head->link;
    free(temp);
    ptr_list->number_of_Nodes--;
}


void list_destroy(struct List * ptr_list)
{
    Node* temp;
    Node* x=NULL;
    temp = ptr_list->head;
    while(temp!=NULL)
    {
      x = temp;
      temp = temp->link;
      free(x);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack)
{
    ptr_Stack -> ptr_list = malloc(sizeof(struct List));
    list_initialize(ptr_Stack->ptr_list);
}
void Stack_push(Stack *ptr_Stack, int key)
{
   list_insert_front(ptr_Stack->ptr_list,key);

}

void Stack_pop(Stack *ptr_Stack)
{
   list_delete_front(ptr_Stack->ptr_list);
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
    return ptr_Stack->ptr_list->head->data; // To return the top element
}

void Stack_destroy(Stack *ptr_Stack)
 {
    list_destroy(ptr_Stack->ptr_list);
}
int match_parenthesis(const char* string)
{
    Stack ptr_Stack;
    Stack_initialize(&ptr_Stack);
   while( ((*string))!='\0' ){
       switch (*string){
       case '(':  Stack_push(&ptr_Stack,1);
            break;
       case '{': Stack_push(&ptr_Stack,2);
            break;
       case '[': Stack_push(&ptr_Stack,3);
            break;
        case ')':
            if(Stack_is_empty(&ptr_Stack) == 1)
              return 0;
            if(Stack_peek(&ptr_Stack)==1)
            Stack_pop(&ptr_Stack);
            else
              return 0;
            break;
        case '}':
            if(Stack_is_empty(&ptr_Stack) == 1)
              return 0;
            if(Stack_peek(&ptr_Stack)==2)
              Stack_pop(&ptr_Stack);
            else
              return 0;
                break;
        case ']':
            if(Stack_is_empty(&ptr_Stack) == 1)
              return 0;
            if(Stack_peek(&ptr_Stack)==3)
              Stack_pop(&ptr_Stack);
            else
              return 0;
            break;

       default:
           break;
       }
        string++;
   }

   int val= Stack_is_empty(&ptr_Stack);
   if(val==0){
       Stack_destroy(&ptr_Stack);
       return 0;
   }
    Stack_destroy(&ptr_Stack);
    return 1;

}