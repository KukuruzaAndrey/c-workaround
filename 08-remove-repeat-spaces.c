#include <stdio.h>

int main() {
  int isLastCharIsSpace = 0;
  int c;
  while((c=getchar()) != EOF) {
    if(c == ' ') {
      if(!isLastCharIsSpace) putchar(c);
      isLastCharIsSpace = 1;
    } else {
      putchar(c);
      isLastCharIsSpace = 0;
    }
  }
}
