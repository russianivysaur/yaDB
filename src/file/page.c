#include "../../include/file/page.h"
#include <stdlib.h>
#include <stdio.h>

Page* new_page(int blocksize) {
  Page* page = (Page*) malloc(sizeof(Page));
  if(page==NULL) return NULL;
  page->buffer = (char*) malloc(blocksize);
  if(page->buffer == NULL) return NULL;
  page->size = blocksize;
  return page;
}


int getInt(Page* page,int offset){
  return (int)(page->buffer[offset]);
}

void setInt(Page* page,int offset,int value){
  page->buffer[offset] = value;
}


// use get Bytes to also read out strings

BytesDescriptor getBytes(Page* page,int offset){
  int length = getInt(page,offset);
  char buf[length];
  BytesDescriptor descriptor;
  descriptor.length = length;
  descriptor.data = &page->buffer[offset + (sizeof(int))];
  return descriptor;
}

void setBytes(Page* page,char data[],int offset,int length) {
  if(page->size<offset+length) {
    printf("content exceeds page length\n");
    return;
  }
  for(int i=0;i<length;i++){
    page->buffer[offset+i] = data[i];
  }
}


static int maxLength(int strLen){
  return strLen;
}