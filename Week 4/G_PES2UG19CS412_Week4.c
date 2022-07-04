#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    //TODO
    Node *newnode = create_node(data);
    Node *aux = NULL;

    if(cll->head == NULL){
        cll->head = cll->tail = newnode;
        newnode->next = newnode;
        cll->length = 0;
        cll->length ++;
    }


    else if(pos > cll->length){
        return;
        }

    else if(pos == 0 && cll->length >= 1){
      Node *aux = cll->head;

       while(aux!=cll->tail){
           aux = aux->next;
       }
       aux->next = newnode;
       newnode->next = cll->head;
       cll->head = newnode;
       cll->length += 1;
    }

    else if(pos == cll->length){
        Node *aux = cll->head;
        while(aux->next != cll->head){
           aux = aux->next;
       }
       aux->next = newnode;
       newnode->next = cll->head;
       cll->tail = newnode;
       cll->length += 1;
    }

    else{
        Node *prev = NULL, *aux = cll->head;
        int c=0;
        while(c < pos){
            prev = aux;
            aux = aux->next;
            c++;
        }
        newnode->next = aux;
        prev->next = newnode;
        cll->length += 1;
    }

}

void position_delete(List* cll, int pos)
{
    //TODO
    if(pos >= cll->length || pos < 0 || cll->head == NULL){
        return ;
    }

    else if(pos == 0){
        Node *aux =cll->head;
        cll->head = aux->next;
        cll->tail->next = cll->head;
        free(aux);
        cll->length --;
    }

    else if(pos == cll->length -1){
        Node *aux = cll->head, *prev = NULL;
        while(aux->next != cll->head){
            prev = aux;
            aux = aux->next;
        }
        prev->next = cll->head;
        cll->tail = prev;
        free(aux);
        cll->length --;
    }
    else{
         Node *aux = cll->head, *prev = NULL;
        int c=0;
        while(c< pos){
            prev = aux;
            aux = aux->next;
            c++;
        }
        prev->next= aux->next;
        free(aux);
        cll->length --;
    }

}

int josephus(List* cll, int k)
{
    //TODO
    Node *aux = cll->head, *prev = aux ;
    int c=1, i=1;

    while(cll->length >1){
        while(i <= (k+c)){
            prev = aux;
            aux = aux->next;
            i++;
        }

        if(aux == cll->head){
            cll->head = aux->next;

        }
        if(aux == cll->tail){
            cll->tail = prev;
        }
        prev->next = aux->next;
       printf("element deleted is %d\n",aux->data);

        free(aux);
        aux = prev->next;

        printf("position set to %d\n",aux->data);

        cll->length -= 1;
        c+=2;
    }

    return aux->data;

}



