#include <stdlib.h>
#include <string.h>
#include "../../include/file/block_id.h"

block_id* new_block_id(char* filename,int number){
  block_id* block = (block_id*)malloc(sizeof(block_id));
  if(block==NULL){
    return NULL;
  }
  block->number = number;
  block->filename = filename;
  return block;
}


int equals(block_id* block1,block_id* block2) {
  return strcmp(block1->filename,block2->filename) && block1->number == block2->number;
}



