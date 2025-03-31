#include "../../include/file/file_manager.h"
#include "../../include/file/block_id.h"
#include "../../include/file/page.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

file_manager* new_file_manager(char* dbDirectory,int blocksize){
  file_manager* manager = (file_manager*) malloc(sizeof(file_manager));
  manager->blocksize = blocksize;
  manager->is_new = 1;
  if(pthread_mutex_init(&manager->mutex,NULL)!=0){
    printf("Cannot init mutex\n");
    return NULL;
  }
  return manager;
}


int get_fd(char* filename) {
  int fd = open(filename,O_CREAT|O_RDWR,0666);
  if(fd<0){
    perror("Error opening file");
    return -1;
  }
  return fd;
}

int fm_length(char* filename){
  int fd = get_fd(filename);
  struct stat file_stat;
  if(fd<0){
    perror("getFile error");
    return -1;
  }
  if(fstat(fd,&file_stat) != 0){
    perror("Stat error\n");
    return -1;
  }
  return file_stat.st_size;
}


void fm_write(file_manager* manager,page* page,block_id* block) {
  pthread_mutex_lock(&manager->mutex);
  int fd = get_fd(block->filename);
  if(fd < 0){
    perror("could not open file\n");
    return;
  }
  lseek(fd,0,SEEK_SET);
  size_t n = write(fd,page->buffer,manager->blocksize);
  if(n != manager->blocksize) {
    perror("write failed\n");
    return;
  }
  pthread_mutex_unlock(&manager->mutex);
}

void fm_read(file_manager* manager,page* page,block_id* block) {
  pthread_mutex_lock(&manager->mutex);
  const int fd = get_fd(block->filename);
  if(fd<0){
    perror("getFile Error\n");
    return;
  }
  lseek(fd,0,SEEK_SET);
  int n = read(fd,page->buffer,manager->blocksize);
  if(n != manager->blocksize){
    printf("read %d bytes\n",n);
    perror("Error reading file\n");
    return;
  }
  pthread_mutex_unlock(&manager->mutex);
}

// append
// writes an empty block to the end of file
block_id* fm_append(file_manager* file_manager,char* filename){
  int size = fm_length(filename);
  pthread_mutex_lock(&file_manager->mutex);
  const int fd = get_fd(filename);
  if(fd < 0){
    return NULL;
  }
  page* page = new_page(file_manager->blocksize);
  if(page==NULL){
    return NULL;
  }
  lseek(fd,size,SEEK_SET);
  int n = write(fd,page->buffer,file_manager->blocksize);
  if(n != file_manager->blocksize){
    printf("%d %d\n",n,file_manager->blocksize);
    perror("fwrite failed in fm_append\n");
    return NULL;
  }
  if(fsync(fd) != 0){
    perror("fsync failed\n");
    return NULL;
  }
  pthread_mutex_unlock(&file_manager->mutex);
  block_id* block_id = new_block_id(filename,100);
  return block_id;
}