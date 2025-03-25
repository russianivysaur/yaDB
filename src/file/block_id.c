#include <stdlib.h>
#include "../../include/file/block_id.h"

BlockId* new_block_id(char* filename,uint32_t number){
  BlockId* block = (BlockId*)malloc(sizeof(BlockId));
  if(block==NULL){
    return NULL;
  }
  block->number = number;
  block->filename = filename;
  return block;
}