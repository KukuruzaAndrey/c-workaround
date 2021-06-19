#include <stdio.h>

int main(){
  printf("Hello world\n");
  int c;
  while((c=getchar())!=EOF) {
    putchar(c);
  }
}
