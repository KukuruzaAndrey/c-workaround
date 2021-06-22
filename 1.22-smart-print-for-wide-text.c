#include <stdio.h>

#define WIDTH 20
void printBuff (char buffer[], int start, int end);
int main() {
  int c;
  int index = 0;
  int lastDividerPos = 0;
  int printedPos = 0;
  char buffer[WIDTH];
  while ((c = getchar()) != EOF) {
    if (index == WIDTH) {
      if (lastDividerPos != 0) {
        printBuff(buffer, printedPos, lastDividerPos);
        printf("\n");
        printBuff(buffer, lastDividerPos, WIDTH);
        index = WIDTH - lastDividerPos;
        printedPos = index;
        lastDividerPos = 0;
      } else {
        printBuff(buffer, printedPos, WIDTH);
        printf("\n");
        index = 0;
      }
    }

    buffer[index] = c;
    index += 1;
    if (c == ' ') {
      lastDividerPos = index;
    }
    if (c == '\n') {
      printBuff(buffer, printedPos, index);
      index = 0;
      lastDividerPos = 0;
      printedPos = 0;
    }
  }
  printBuff(buffer, printedPos, index);
}

void printBuff (char buffer[], int start, int end) {
  for (int i = start; i < end; i++) {
    putchar(buffer[i]);
  }
}
