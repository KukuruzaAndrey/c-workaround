/* не працює детект розмірів терміналу коли стдін
приатачено до файлу. імовірно потрібно зчитувати
шлях до файлу як параметр */

// count chars from 33 to 126 inclusively
// build histogram checks width of terminal
#include <stdio.h>
#include <sys/ioctl.h>

int main(){
  // detect terminal width
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  printf("%d\n", w.ws_col);
  int termWidth = w.ws_col;
  printf("%d", termWidth);
  int countChars[94] = { 0 };
  int c;
  // count chars from input
  while ((c = getchar()) != EOF) {
    if (c > 32 && c < 127) {
      countChars[c - 33]+=1;
    }
  }

  // find char with higest frequency
  // count chars with non-zeros freq
  int maxCount = 0;
  int nonZerosFreqCount = 0;
  for (int i = 0; i < 94; i++) {
    if (countChars[i] == 0) {
      nonZerosFreqCount++;
    }
    if (countChars[i] > maxCount) {
      maxCount = countChars[i];
    }
  }

// return 0;
  // print histogram considering width of term
  int i = 0;
  do {
  int start = i * termWidth;
  int end = (i + 1) * termWidth > nonZerosFreqCount ?
            maxCount :
            (i + 1) * termWidth;
  for (int row = maxCount; row > 0; row--) {
    for (int i = start; i < end; i++) {
      if (countChars[i] == 0) continue;
      if (row <= countChars[i]) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  for (int i = start; i < end; i++) {
    if (countChars[i] != 0)
    printf("%c", i + 33);
  }
  printf("\n");
  i++;
  } while (termWidth * i < nonZerosFreqCount);
  printf("\n");
}

