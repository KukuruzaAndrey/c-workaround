#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//uint8_t hex2int(char *hex);
void hextobin(const char * str, uint8_t * bytes, size_t blen);

int main() {
  char hexstr[] = "1F";
  //uint8_t hex = hex2int(hexstr);
  //char *p;
  //printf("%x - %s\n", hex, hexstr);
  //printf("%s - %lu\n", hexstr, strtoul(hexstr, &p, 16));
  char t[] = "aaff00220033003300BD";
  int bytes = strlen(t)/2;
  uint8_t * mem = (uint8_t*)malloc(bytes * sizeof(uint8_t));
  //for(int i = 0; i < bytes; i++){
  //  *mem = 
  //}
  hextobin(t, mem, bytes);
  printf("%s\n", t);
  for (int i = 0; i < bytes; i++) {
    printf("%02X", mem[i]);
  }
  printf("\n");
}
/**
 * hex2int
 * take a hex string and convert it to a 32bit number
 * (max 8 hex digits)
 */
uint8_t hex2uint8_t(char *hex) {
    uint8_t val = 0;
    while (*hex) {
        // get current character then increment
        uint8_t byte = *hex++;
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;    
        // shift 4 to make space for new digit, and add the 4 bits of the new digit 
        val = (val << 4) | (byte & 0xF);
    }
    return val;
}

// Based on https://stackoverflow.com/a/23898449/266720
void hextobin(const char * str, uint8_t * bytes, size_t blen)
{
   uint8_t  pos;
   uint8_t  idx0;
   uint8_t  idx1;

   // mapping of ASCII characters to hex values
   const uint8_t hashmap[] =
   {
     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, // 01234567
     0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89:;<=>?
     0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, // @ABCDEFG
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // HIJKLMNO
   };

   memset(bytes, 0, blen);
   for (pos = 0; ((pos < (blen*2)) && (pos < strlen(str))); pos += 2)
   {
      idx0 = ((uint8_t)str[pos+0] & 0x1F) ^ 0x10;
      idx1 = ((uint8_t)str[pos+1] & 0x1F) ^ 0x10;
      bytes[pos/2] = (uint8_t)(hashmap[idx0] << 4) | hashmap[idx1];
   };
}
