#include <stdlib.h>
#ifndef PAGE_H
#define PAGE_H

typedef struct{
  char* buffer;
  int size;
} Page;


typedef struct{
  char* data;
  int length;
} BytesDescriptor;


Page* new_page(int);

#endif