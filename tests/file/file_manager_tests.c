#include "../../include/file/file_manager.h"
#include "../../include/file/page.h"
#include "../../include/file/block_id.h"
#include <stdlib.h>
#include <stdio.h>

int file_manager_test() {
  file_manager* manager = new_file_manager("dbdir",100);
  if(manager==NULL){
    return -1;
  }
  free(manager->db_directory);
  free(manager);
  return 0;
}

int read_test(){
  const int blocksize = 100;
  file_manager* manager = new_file_manager("dbdir",blocksize);
  page* page = new_page(blocksize);
  if(page==NULL){
    return -1;
  }
  block_id* block = new_block_id("test_file",1);
  read(manager,page,block);
  remove(block->filename);
  return 0;
}


int main(void){
  if(file_manager_test() != 0){
    return -1;
  }
  if (read_test() != 0) {
    return -1;
  }
  return 0;
}