#ifndef LOGMANAGER_H
#define LOGMANAGER_H
#include "../file/file_manager.h"
#include "iterator.h"

typedef struct{
  file_manager* fm;
  page* log_page;
  char* log_file;
  block_id* current_blk;
  int latest_lsn;
  int last_saved_lsn;
  pthread_mutex_t mutex;
} log_manager;

log_manager* new_log_manager(file_manager*,char*);
void flush(int);
iterator* get_iterator();
int append(char*,size_t);

#endif