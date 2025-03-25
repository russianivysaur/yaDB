#include "../../include/file/page.h"
#include <stdlib.h>

Page* new_page(size_t blocksize) {
  Page* page = (Page*) malloc(sizeof(Page));
  if(page==NULL) return NULL;
  page->buffer = (uint8_t*) malloc(blocksize);
  if(page->buffer == NULL) return NULL;
  page->size = blocksize;
  return page;
}