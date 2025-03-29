#include "../../include/file/file_manager.h"
#include "../../include/lib/hashmap.h"
#include "../../include/file/block_id.h"
#include "../../include/file/page.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

FileManager* newFileManager(char* dbDirectory,int blocksize){
  FileManager* fileManager = (FileManager*)malloc(sizeof(FileManager));
  fileManager->blocksize = blocksize;
  fileManager->isNew = 1;
  fileManager->openFiles = new_hashmap();
  return fileManager;
}


FILE* getFile(char* filename) {
  FILE* file = fopen(filename,"a+");
  if(file==NULL){
    perror("Error opening file");
    return NULL;
  }
  return file;
}

void read(BlockId* block,Page* page) {
  FILE* file = getFile(block->filename);
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
}


int length(char* filename){
  FILE* file = getFile(filename);
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