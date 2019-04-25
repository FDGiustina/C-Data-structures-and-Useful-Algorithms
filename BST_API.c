#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Por enquanto a inserção, impressão, busca e sucessor funcionam. Falta implementar as rotações e a remoção de um nodo que
  não esteja na folha.
  A unica maneira que encontrei de implementar a árvore sem gerar problemas de ponteiro foi retornar um nodo nas funções.
  Pode parecer estranho mas funciona.
  TO DO:
    - Implementar rotações a direita e a esquerda
    - Implementar remoção de um nodo diferente da folha
    - Implementar a AVL
*/


typedef struct node{
  int key;
  int h;
  struct node *right,*left,*p;
}node;

node* insertion(node *n, int x){ //recebe nodo e chave
  if(n == NULL){
    n = malloc(sizeof(node));
    n->p = NULL;
    n->right = NULL;
    n->left = NULL;
    n->h = -1;
    n->key = x;
    return n;
  }
  if(n->key >= x)
    n->left = insertion(n->left,x);
  else //  n->key < x)
    n->right = insertion(n->right,x);
  return n;
}

node* search(node *t,int x){//retorna endereço de nodo
  node *aux = t;
  while(aux != NULL){
    if(aux->key == x){
      return aux;
    }
    if(aux->key <= x){
      aux = aux->right;
    }
    if(aux->key > x){
      aux = aux->left;
    }
  }
  return NULL;
}

node* sucessor(node *t){// retorna endereço de sucessor
  node* aux;
  aux = t->right;
  if(aux==NULL)
     return NULL;
  while(aux->left != NULL){
    aux = aux->left;
  }
  return aux;
}

void remove_node(node *t,int x){
  node *aux,*aux2;

  aux = search(t,x);
  if(aux->left == NULL && aux->right == NULL){
    aux2 = sucessor(aux)->left;
    aux->key = aux2->key;
    free(aux2);
  }
}

void printtree(node *n){ // imprime arvore
  if(n == NULL){
    return;
  }
  printtree(n->left);
  printf("%d %d\n",n->key,n->h);
  printtree(n->right);
}

int main(){
  node *t = NULL;
  node *s = NULL;
  int y[15] = {30,20,40,10,50,15,37,9,12,13,17,35,39,55,60};
  int i;
  for(i=0;i<15;i++){
    t = insertion(t,y[i]);
  }

  //printtree(t);
  //remove_node(t,17);
  printf("\n");
  //printf("%d\n",t->key);
  //s = search(t,18);
  printtree(t);
  //printf("%d",t->key);
  //printf("%d",s->key);
}
