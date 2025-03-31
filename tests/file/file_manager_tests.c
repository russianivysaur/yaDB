#include <math.h>

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

int append_test() {
  const int blocksize = 100;
  char* test_file = "test_file";
  file_manager* manager = new_file_manager("dbdir",blocksize);
  if (manager==NULL) {
    return -1;
  }
  fm_append(manager,test_file);
  remove(test_file);
  return 0;
}

int read_test(){
  const int blocksize = 100;
  file_manager* manager = new_file_manager("dbdir",blocksize);
  page* page = new_page(blocksize);
  if(page==NULL){
    return -1;
  }
  char* test_file = "test_file";
  block_id* block = new_block_id(test_file,0);
  fm_read(manager,page,block);
  remove(test_file);
  return 0;
}


int append_read_write_read_test() {
  const int blocksize = 100;
  char* test_filename = "test_file";
  file_manager* file_manager = new_file_manager("dbdir",blocksize);
  if (file_manager==NULL) {
    return -1;
  }
  block_id* new_block = fm_append(file_manager,test_filename);
  if (new_block==NULL) {
    return -1;
  }
  page* page1 = new_page(file_manager->blocksize);
  if (page1==NULL) return -1;
  fm_read(file_manager,page1,new_block);
  const int test_val = 200;
  set_int(page1,0,test_val);
  fm_write(file_manager,page1,new_block);
  // check if the page has valid content
  page1 = new_page(file_manager->blocksize);
  fm_read(file_manager,page1,new_block);
  int actual = get_int(page1,0);
  if (actual != test_val) {
    printf("expected %d, got %d\n",test_val,actual);
    return -1;
  }
  free(page1->buffer);
  free(page1);
  free(new_block->filename);
  free(new_block);
  free(file_manager);
  return 0;
}


int main(void){
  if(file_manager_test() != 0){
    return -1;
  }
  if (read_test() != 0) {
    return -1;
  }
  if (append_test() != 0) {
    return -1;
  }
  if (append_read_write_read_test() != 0) {
    return -1;
  }
  return 0;
}
