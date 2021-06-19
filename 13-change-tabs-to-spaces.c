#include <stdio.h>

#define SPACE_COUNT 8

int main(){
  int c;
  int charsToTabStop = SPACE_COUNT;
  while ((c=getchar()) != EOF){
    if (c == '\t') {
      for (int i = 0; i < charsToTabStop; i++) {
        putchar(' ');
      }
      charsToTabStop = SPACE_COUNT;
    } else {
      putchar(c);
      charsToTabStop -= 1;
    }
    if (c == '\n' || charsToTabStop == 0) {
      charsToTabStop = SPACE_COUNT;
    }
  }
}
