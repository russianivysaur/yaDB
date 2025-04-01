#include "../include/lib/hashmap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// fixed size hashmap
hashmap* new_hashmap(int cap) {
  hashmap* map = (hashmap*)malloc(sizeof(hashmap));
  map->len = 0;
  map->cap = cap;
  map->data = (void**)malloc(sizeof(void*)*cap);
  return map;
}


void put(hashmap* map,void* key,size_t key_length,void* value,size_t value_length){
  char* malloced_value = (char*)malloc(value_length);
  if(malloced_value==NULL) {
    perror("could not malloc\n");
    return;
  }
  memcpy(malloced_value,value,value_length);
  unsigned int sum = 0;
  char* key_start = (char*)key;
  for(int i=0;i<key_length;i++){
    sum += key_start[i];
  }
  int slot = sum % map->cap;
  map->data[slot] = malloced_value;
}


void* get(hashmap* map,void* key,size_t key_length) {
  unsigned int sum = 0;
  char* key_start = (char*)key;
  for(int i=0;i<key_length;i++){
    sum += key_start[i];
  }
  int slot = sum % map->cap;
  return map->data[slot];
}