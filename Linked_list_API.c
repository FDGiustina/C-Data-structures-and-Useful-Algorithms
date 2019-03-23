#include<stdio.h>
#include<stdlib.h>

typedef struct node* pointer;

typedef struct node{
  int key;
  pointer next,previous;
}node;

typedef struct linked_list{
  pointer head,last;
}linked_list;

void create_list(linked_list *l){
  l->head = (pointer)malloc(sizeof(node));
  l->head->next = NULL;
  l->last = l->head;
  l->head->previous = NULL;
  l->last->previous = l->head;
}

void new_node(linked_list *l){
  pointer aux = l->last;
  l->last->next = (pointer)malloc(sizeof(node));
  l->last = l->last->next;
  l->last->next = NULL;
  l->last->previous = aux;
}

void insert_key(linked_list *l,int x){
  pointer aux = l->last;
  l->last->next = (pointer)malloc(sizeof(node));
  l->last = l->last->next;
  l->last->next = NULL;
  l->last->previous = aux;
  l->last->key = x;
}

void remove_key(linked_list *l,int x){
  pointer aux1,aux2;
  aux1 = l->head->next;
  while(aux1 != NULL){
    aux2 = aux1->next;
    if(aux1->key == x){
      if(aux1 != l->last){
        aux1->next->previous = aux1->previous;
      }
      else{
          l->last = aux1->previous;
      }
      aux1->previous->next = aux1->next;
      free(aux1);
    }
    aux1 = aux2;
  }
}


node* node_search(linked_list *l,int x){
  pointer aux = l->head->next;
  while(aux != NULL ){
    if(aux->key == x){
      return(aux);
    }
    aux = aux->next;
  }
  return(NULL);
}


void node_switch(int x,int y,linked_list *l){
  pointer aux1,aux2;
  int i;
  aux1 = node_search(l,x);
  aux2 = node_search(l,y);
  if(aux1 == NULL || aux1 == NULL){
    return;
  }
  i = aux1->key;
  aux1->key = aux2->key;
  aux2->key = i;
}

void print_list(linked_list *l){
  pointer aux = l->head->next;
  while(aux != NULL){
    printf("%d \n",aux->key);
    aux = aux->next;
  }
}

void print_list_backwards(linked_list *l){
  pointer aux = l->last;
  while(aux != l->head){
    printf("%d\n",aux->key);
    aux = aux->previous;
  }
}

void empty_list(linked_list *l){
  pointer aux = l->head->next;
  pointer aux2;
  while(aux != NULL){
    aux2 = aux->next;
    remove_key(l,aux->key);
    aux = aux2;
  }
}

int list_length(linked_list *l){
  pointer aux = l->head->next;
  int i = 0;
  while(aux != NULL){
    i++;
    aux = aux->next;
  }
  return(i);
}


int main(){
  return 0;
}
