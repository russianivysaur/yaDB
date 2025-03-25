#include <stdint.h>
#ifndef BLOCK_ID_H
#define BLOCK_ID_H

typedef struct{
  char* filename;
  uint32_t number;
} BlockId;

BlockId* new_block_id(char*,uint32_t);

#endif