#include <stdint.h>
#ifndef BLOCK_ID_H
#define BLOCK_ID_H

typedef struct{
  char* filename;
  int number;
} BlockId;

BlockId* new_block_id(char*,int);

#endif