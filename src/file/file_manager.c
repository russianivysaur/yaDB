#include "../../include/file/file_manager.h"
#include "../../include/lib/hashmap.h"
#include <stdlib.h>
#include <stdbool.h>

FileManager* new_file_manager(char* dbDirectory,int blocksize){
  FileManager* fileManager = (FileManager*)malloc(sizeof(FileManager));
  fileManager->blocksize = blocksize;
  fileManager->isNew = 1;
  fileManager->openFiles = new_hashmap();
  return fileManager;
}