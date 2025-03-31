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
  int value = 0;
  for(int i=0;i<sizeof(int);i++){
    printf("reading %2x at %d\n",(unsigned char)page->buffer[offset+i],i);
    value |= (0x000000ff & page->buffer[offset+i]);
    value = value<<(24 - (8*i));
    printf("%d",value);
  }
  return value;
}

void set_int(page* page,int offset,int value){
  for(int i=offset+sizeof(int)-1;i>=offset;i--){
    printf("writing %2x at %d\n",value,i);
    page->buffer[i] = value;
    value >>= 8;
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