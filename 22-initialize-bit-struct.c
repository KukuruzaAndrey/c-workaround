#include <stdio.h>

int main(){
  struct st {
    unsigned int a:2;
    unsigned int b:4;
  };

  struct st c;
  c = (struct st){3, 0};
 // c = (struct st){2, 5};
  // 10 0101
  // 11010110

 // c = (struct st){3, 0};
  // 11 0000
  // 11000011

  struct st * pointer = &c;
  printf("%p %ld\n", pointer, sizeof(pointer));
  char *p = (char *) pointer;
  printf("%p %ld\n", p, sizeof(p));
  printf("%02x \n", *p);
}
