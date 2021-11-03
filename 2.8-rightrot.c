// cyclic shifts x for right on n bits
#include <stdio.h>
#include <stdint.h>

uint8_t rightrot(uint8_t x, int n) {
  uint8_t left = x << (8 - n);
  uint8_t rigth = x >> n & ~0 << (8 - n);
  return left | rigth;
}

int main() {
  printf("%0X - F0\n", rightrot(0b00001111, 4));
  printf("%0X - C2\n", rightrot(0b00001111, 2));
}