#include "../../include/log/log_manager.h"
#include "../../include/log/iterator.h"
#include <stdlib.h>

log_manager* new_log_manager(file_manager* fm,char* log_file){
  log_manager* manager = (log_manager*) malloc(sizeof(log_manager));
  manager->fm = fm;
  manager->last_saved_lsn = -1;
  manager->latest_lsn = -1;
  manager->log_file = log_file;
  manager->log_page = log_page;
  return manager;
}

void flush(int){

}

iterator* get_iterator(){

}

int append(char*,size_t){

}