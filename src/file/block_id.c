#include <stdlib.h>
#include <string.h>
#include "../../include/file/block_id.h"

BlockId* new_block_id(char* filename,int number){
  BlockId* block = (BlockId*)malloc(sizeof(BlockId));
  if(block==NULL){
    return NULL;
  }
  block->number = number;
  block->filename = filename;
  return block;
}


char* filename(BlockId* block) {
  return block->filename;
}

int number(BlockId* block) {
  return block->number;
}

int equals(BlockId* block1,BlockId* block2) {
  return strcmp(block1->filename,block2->filename) && block1->number == block2->number;
}



