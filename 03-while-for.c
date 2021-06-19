#include <stdio.h>

int main() {
  printf("hex numbers from 0 to 100\n");
  for(int i=0;i<101;i++){
    printf("%03d - %05x\n", i, i);
  }
  printf("\nnumbers while cube of number less 1000\n");
  int i = 0;
  while(i*i*i<1000){
    printf("%d - %d\n", i, i*i*i);
    i++;
  }
}
