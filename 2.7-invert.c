#include <stdio.h>
#include <stdint.h>

void printbin(char c) {
  char bits[8];
  unsigned char value = c;

  for (int i = 7; i >= 0; i -= 1) {
    bits[i] = '0' + (value & 0x01);
    value >>= 1;
  }
  puts(bits);
}

uint8_t invert(uint8_t num, int pos, int len) {
  uint8_t mask = ~(~0 << len) << (pos - len + 1);
  return num & ~mask | ~num & mask;
}

int main() {
  printf("%X-3F\n", invert(0b00110011, 3, 2));
  printf("%X-03\n", invert(0b00110011, 5, 2));
}
