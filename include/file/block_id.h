#ifndef BLOCK_ID_H
#define BLOCK_ID_H

typedef struct{
  char* filename;
  int number;
} block_id;

block_id* new_block_id(char*,int);

#endif