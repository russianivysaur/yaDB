#include <stdint.h>
#ifndef BLOCK_ID_H
#define BLOCK_ID_H

typedef struct{
  char* filename;
  int number;
} BlockId;

BlockId* newBlockId(char*,int);

#endif