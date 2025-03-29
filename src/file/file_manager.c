#include "../../include/file/file_manager.h"
#include "../../include/file/block_id.h"
#include "../../include/file/page.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

file_manager* new_file_manager(char* dbDirectory,int blocksize){
  file_manager* manager = (file_manager*) malloc(sizeof(file_manager));
  manager->blocksize = blocksize;
  manager->is_new = 1;
  if(pthread_mutex_init(&manager->mutex,NULL)!=0){
    printf("Cannot init mutex\n");
    return NULL;
  }
  return manager;
}


FILE* get_file(char* filename) {
  FILE* file = fopen(filename,"a+");
  if(file==NULL){
    perror("Error opening file");
    return NULL;
  }
  return file;
}

void read(file_manager* manager,page* page,block_id* block) {
  pthread_mutex_lock(&manager->mutex);
  FILE* file = get_file(block->filename);
  if(file==NULL){
    perror("getFile Error\n");
    return;
  }
  if(fseek(file,0,SEEK_SET) != 0){
    perror("Error seeking file");
    return;
  }
  if(fread(page->buffer,page->size,1,file) != 0){
    perror("Error reading file");
    return;
  }
  pthread_mutex_unlock(&manager->mutex);
}


int length(char* filename){
  FILE* file = get_file(filename);
  if(file==NULL){
    perror("getFile error");
    return -1;
  }
  if(fseek(file,0,SEEK_END) != 0){
    perror("Seek failed");
    return -1;
  }
  return ftell(file);
}