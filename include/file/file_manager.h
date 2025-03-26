#include <stdbool.h>
#include <stdio.h>
#include "../lib/hashmap.h"
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

typedef struct{
  int blocksize;
  bool isNew;
  FILE* dbDirectory;
  HashMap* openFiles;
}FileManager;


FileManager* new_file_manager();

#endif