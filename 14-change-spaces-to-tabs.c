#include <stdio.h>

#define SPACE_COUNT 8

int main(){
  int c;
  int charsToTabStop = SPACE_COUNT;
  int spacesInRow = 0;
  while ((c=getchar()) != EOF) {
    if (c == ' ') {
      charsToTabStop -= 1;
      spacesInRow += 1;
      if (charsToTabStop == 0 && spacesInRow > 1) {
        spacesInRow = 0;
        putchar('\t');
      }
    } else {
      if (spacesInRow > 0) {
        for (int i = 0; i < spacesInRow; i++) {
          putchar(' ');
        }
        spacesInRow = 0;
      }
      charsToTabStop -= 1;
      putchar(c);
    }

    if (c == '\t' || c == '\n' || charsToTabStop == 0) {
      charsToTabStop = SPACE_COUNT;
    }
  }
}
