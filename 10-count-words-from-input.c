#include <stdio.h>

int main(){
  int countWords = 0;
  int c;
  int insideWord = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (insideWord) {
         countWords++;
         insideWord = 0;
      }
    } else {
      if (!insideWord) {
        insideWord = 1;
      }
    }
  }
  printf("Count of words: %d\n", countWords);
}
