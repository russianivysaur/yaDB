#ifndef PAGE_H
#define PAGE_H

typedef struct{
  char* buffer;
  int size;
} page;


typedef struct{
  char* data;
  int length;
} bytes_descriptor;


page* new_page(int);
// integer functions
void set_int(page*,int,int);
int get_int(page*,int);

//byte functions
void set_bytes(page*,int,char*,int);
bytes_descriptor get_bytes(page*,int);

#endif