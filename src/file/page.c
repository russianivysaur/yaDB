#include <stdlib.h>
#include <stdio.h>
#include "../../include/file/page.h"

page* new_page(int blocksize) {
  page* new_page = (page*) malloc(sizeof(page));
  if(new_page==NULL) return NULL;
  new_page->buffer = (char*) malloc(blocksize);
  if(new_page->buffer == NULL) return NULL;
  new_page->size = blocksize;
  return new_page;
}


int get_int(page* page,int offset){
  char valueBytes[sizeof(int)];
  int value = 0;
  for(int i=0;i<sizeof(int);i++){
    value |= page->buffer[offset+i];
    value << 8;
  }
  return value;
}

void set_int(page* page,int offset,int value){
  char* valueBytes = (char*) &value;
  for(int i=0;i<sizeof(offset);i++){
    page->buffer[offset+i] = valueBytes[i];
  }
}



// use get Bytes to also read out strings

bytes_descriptor get_bytes(page* page,int offset){
  int length = get_int(page,offset);
  char buf[length];
  bytes_descriptor descriptor;
  descriptor.length = length;
  descriptor.data = &page->buffer[offset + (sizeof(int))];
  return descriptor;
}

void set_bytes(page* page,int offset,char* data,int length) {
  set_int(page,offset,length);
  offset += sizeof(int);
  if(page->size<offset+length) {
    printf("content exceeds page length\n");
    return;
  }
  for(int i=0;i<length;i++){
    page->buffer[offset+i] = data[i];
  }
}


static int max_length(int strLen){
  return strLen;
}