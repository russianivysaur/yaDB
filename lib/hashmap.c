#include "../include/lib/hashmap.h"
#include <stdlib.h>
#include <stdio.h>

// fixed size hashmap
hashmap* new_hashmap(int cap) {
  hashmap* map = (hashmap*)malloc(sizeof(hashmap));
  map->len = 0;
  map->cap = cap;
  map->data = (void**)malloc(sizeof(void*)*cap);
  return map;
}


void put(hashmap* map,void* key,size_t key_length,void* value){
  int sum = 0;
  char* key_start = (char*)key;
  for(int i=0;i<key_length;i++){
    sum += key_start[i];
  }
  int slot = sum % map->cap;
  map->data[slot] = value;
}


void* get(hashmap* map,void* key,size_t key_length) {
  int sum = 0;
  char* key_start = (char*)key;
  for(int i=0;i<key_length;i++){
    sum += key_start[i];
  }
  int slot = sum % map->cap;
  return map->data[slot];
}