#include <stdio.h>

#include <stdint.h>

uint8_t getbits(int n, int start, int len) {
  //printf("%d\n", n>>start);
  //printf("%d\n", ~0 << len);
  //printf("%d\n", ~(~0 << len));
  return (n>>start) & ~(~0 << len);
}

uint8_t setbits(int num, int p, int len, int donor) {
  return num | (donor << (p-len+1)) & ~(~0 << (p+1));
}


int main() {
  printf("%d = 5\n", getbits(0b10101010, 3, 3));
  printf("%d = 7\n", getbits(0b10111010, 3, 3));
  printf("%d = 170\n", getbits(0b10101010, 0, 8));
  printf("%d = 21\n", getbits(0b10101010, 1, 5));

  printf("%d = 193\n", setbits(0b00000001, 7, 2, ~0));
  printf("%d = 29\n", setbits(0b00000001, 4, 3, ~0));

}
