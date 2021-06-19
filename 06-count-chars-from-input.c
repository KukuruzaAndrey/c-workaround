#include <stdio.h>

int main(){
  int count = 0;
  int c;
  while((c = getchar()) != EOF){
    count++;
  }
  printf("Count of chars: %d\n", count);
}
