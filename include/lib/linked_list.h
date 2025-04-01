#ifndef LL_H
#define LL_H

typedef struct {
  void* data;
  void* next;
} node;


typedef struct{
  int length;
  node* head;
  node* tail;
} ll;


ll* new_ll();
void add(ll*,node*);

#endif