#ifndef LINKED_LIST_API_HEADER
#define LINKED_LIST_API_HEADER

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

void create_list(linked_list *l);
void new_node(linked_list *l);
void insert_key(linked_list *l,int x);
void remove_key(linked_list *l,int x);
node* node_search(linked_list *l,int x);
void node_switch(int x,int y,linked_list *l);
void print_list(linked_list *l);
void print_list_backwards(linked_list *l);
void empty_list(linked_list *l);
int length_list(linked_list *l);
#endif // LINKED_LIST_API_HEADER
