#include <stdio.h>
#include <stdint.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main() {
    uint8_t a = 0;
    printf("0 "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));
    a = 1;
    printf("1 "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));
    a <<= 1;
    printf("1 << 1 "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));
    a <<= 7;
    printf("1 << 8 "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));
    a |= 0b01010101;
    printf("|01.. "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));
    a &= 0b01010101;
    printf("&01.. "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));
    a &= 0b10101010;
    printf("&10.. "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(a));

    return 0;
}
