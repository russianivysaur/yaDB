#include <stdint.h>
#include <stdlib.h>
#ifndef PAGE_H
#define PAGE_H

typedef struct{
  uint8_t* buffer;
  size_t size;
} Page;


Page* new_page(size_t);

#endif