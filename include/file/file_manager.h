#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <stdbool.h>
#include <stdio.h>
#include "block_id.h"
#include "page.h"
#include <pthread.h>

typedef struct{
  int blocksize;
  bool is_new;
  FILE* db_directory;
  pthread_mutex_t mutex;
}file_manager;


file_manager* new_file_manager(char*,int);
block_id* fm_append(file_manager*,char*);
void fm_write(file_manager*,page*,block_id*);
void fm_read(file_manager*,page*,block_id*);

#endif