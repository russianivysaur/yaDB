#include "../../include/file/block_id.h"
#include <string.h>
int main(void) {
  char filename[256] = "test_filename";
  int number = 2354;
  block_id* block_id = new_block_id(&filename[0],number);
  if(strcmp(block_id->filename,filename) != 0) {
    return -1;
  }
  if(block_id->number != number){
    return -1;
  }
  return 0;
}