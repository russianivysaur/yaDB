#include "../../include/file/page.h"
#include <stdio.h>
#include <string.h>

int newPageTest() {
  int blocksize = 100;
  Page* page = newPage(blocksize);
  if(page==NULL){
    return -1;
  }
  if(page->size != blocksize){
    return -1;
  }
  free(page);
  return 0;
}

int setIntTest() {
  int blocksize = 100;
  Page* page = newPage(blocksize);
  if(page==NULL){
    return -1;
  }
  int val = 10;
  int offset = 50;
  setInt(page,offset,val);
  int value = getInt(page,offset);
  if(value != val){
    return -1;
  }
  free(page);
  return 0;
}


int setBytesTest() {
  int blocksize = 100;
  Page* page = newPage(blocksize);
  if(page==NULL){
    return -1;
  }
  char data[] = "Ankit\n";
  int offset = 10;
  setBytes(page,offset,data,strlen(data));
  BytesDescriptor descriptor = getBytes(page,offset);
  if(descriptor.length != strlen(data)){
    printf("Bytes length does not match\n");
    return -1;
  }

  for(int i=0;i<strlen(data);i++){
    if(descriptor.data[i] != data[i]){
      printf("Byte does not match at %d\n",i);
      return -1;
    }
  }

  return 0;
}

int main(void){
  if(newPageTest()!=0){
    return -1;
  }
  if(setIntTest()!=0){
    return -1;
  }
  if(setBytesTest()!=0){
    return -1;
  }
  return 0;
}

