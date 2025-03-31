#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdlib.h>
typedef struct {
  int len;
  void** data;
  int cap;
} hashmap;


hashmap* new_hashmap(int);
void put(hashmap*,void*,size_t,void*);
void* get(hashmap*,void*,size_t);

#endif