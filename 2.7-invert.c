#include <stdio.h>
#include <stdint.h>

uint8_t invert(uint8_t num, int pos, int len) {
  return num & ( ~(~0 << pos) | 
}

int main() {
  printf("%x-3F\n", invert(0b00110011, 3, 2));
  printf("%x-03\n", invert(0b00110011, 5, 2));
}
