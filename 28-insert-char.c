#include <stdio.h>
#include <string.h>

//assume buffer have space
void insertc(char c, char * buf, unsigned pos) {
  memmove(buf+pos+1, buf+pos,1);
  buf[pos] = c;
}

char a[50] = "abcdefhgklmop";
int main() {
  printf("%s\n", a);
  insertc('Q', a, 5);
  printf("%s\n", a);
}}
