#include "../../include/file/page.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int newpageTest() {
  int blocksize = 100;
  page* page = new_page(blocksize);
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
  page* page = new_page(blocksize);
  if(page==NULL){
    return -1;
  }
  int val = 200;
  int offset = 50;
  set_int(page,offset,val);
  int value = get_int(page,offset);
  if(value != val){
    printf("expected %d,got %d\n",val,value);
    return -1;
  }
  free(page);
  return 0;
}


int setBytesTest() {
  int blocksize = 100;
  page* page = new_page(blocksize);
  if(page==NULL){
    return -1;
  }
  char data[] = "Ankit\n";
  int offset = 10;
  set_bytes(page,offset,data,strlen(data));
  bytes_descriptor descriptor = get_bytes(page,offset);
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
  if(newpageTest()!=0){
    return -1;
  }
  if(setIntTest()!=0){
    return -1;
  }
//  if(setBytesTest()!=0){
//    return -1;
//  }
  return 0;
}

