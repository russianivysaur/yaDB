#ifndef HASHMAP_H
#define HASHMAP_H
#include <stddef.h>
typedef struct {
  int len;
  void** data;
  int cap;
} hashmap;


hashmap* new_hashmap(int);
void put(hashmap*,void*,size_t,void*,size_t);
void* get(hashmap*,void*,size_t);

#endif