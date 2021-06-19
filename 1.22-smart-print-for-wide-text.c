#include <stdio.h>

#define WIDTH 20
int readNChars (char line[], int n);

int main() {
  int c;
  int index = 0;
  int lastDividerPos = 0;
  char buffer[WIDTH];
  while ((c = getline()) != EOL) {
    if (index == WIDTH) {
      if (lastDividerPos != 0) {
        printBuff(buffer, 0, lastDividerPos);
        printf("\n");
        printBuff(buffer, lastDividerPos, WIDTH);
        index = WIDTH - lastDividerPos;
      } else {
        
      }
    }
    buffer[index] = c;
    index += 1;
  }
}
/*
int readNChars (char) {
  
}*/
