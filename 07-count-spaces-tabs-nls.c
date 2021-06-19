#include <stdio.h>

int main(){
  int countSpaces = 0;
  int countTabs = 0;
  int countNls = 0;
  int c;
  while((c=getchar()) != EOF){
    if(c == ' ') countSpaces++;
    if(c == '\t') countTabs++;
    if(c == '\n') countNls++;
  }
  printf("Count of spaces: %d\n", countSpaces);
  printf("Count of tabs: %d\n", countTabs);
  printf("Count of lines: %d\n", countNls);
  printf("Total: %d\n", countSpaces+countTabs+countNls);
}
