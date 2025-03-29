#include "../../include/file/block_id.h"
#include <string.h>
int main(void) {
  char filename[256] = "test_filename";
  int number = 2354;
  BlockId* blockId = newBlockId(&filename[0],number);
  if(strcmp(blockId->filename,filename) != 0) {
    return -1;
  }
  if(blockId->number != number){
    return -1;
  }
  return 0;
}