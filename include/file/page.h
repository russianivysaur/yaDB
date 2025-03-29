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


Page* newPage(int);
// integer functions
void setInt(Page*,int,int);
int getInt(Page*,int);

//byte functions
void setBytes(Page*,int,char*,int);
BytesDescriptor getBytes(Page*,int);

#endif