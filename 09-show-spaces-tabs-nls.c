#include <stdio.h>

int main(){
  int countSpaces = 0;
  int countTabs = 0;
  int countNls = 0;
  int c;
  while((c=getchar()) != EOF){
    if(c == ' ') {
      putchar('.');
    } else if(c == '\t') {
      putchar('\\');
      putchar('t');
    } else if(c == '\n') {
      putchar('\\');
      putchar('n');
      putchar('\n');
    } else {
      putchar(c);
    }
  }
}
