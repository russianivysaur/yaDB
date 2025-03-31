#include "../../include/lib/hashmap.h"
#include <string.h>
#include <stdio.h>

int main(void){
  hashmap* map = new_hashmap(10);
  char* key = "keyye";
  char* value = "val4324";
  put(map,&key,strlen(key),value);
  char* actual = (char*)get(map,&key,strlen(key));
  if(actual != value){
    printf("expected %s,got %s\n",value,actual);
    return -1;
  }
  return 0;
}