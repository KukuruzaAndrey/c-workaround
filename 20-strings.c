#include <stdio.h>
#include <stdint.h>

int mystrlen (char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

int myatoi (char a) {
  if (a >= '0' && a <= '9') {
    return a - '0';
  } else {
    return -1;
  }
}

int pointeratoi (char * a) {
  if (*a >= '0' && *a <= '9') {
    return a - '0';
  } else {
    return -1;
  }
}

int htoi (char h) {
  if (h >= 'A' && h <= 'F') {
    return h - 'A' + 10;
  } else if (h >= 'a' && h <= 'f') {
    return h - 'a' + 10;
  } else if (h >= '0' && h <= '9') {
    return h - '0';
  } else {
    return -1;
  }
}

int32_t stringToInt(char * str) {
  while (str != '\0') {
    
  }
}

int main () {
  char s1[] = "abcd";
  char s2[] = "123056789";
  printf("%d %d\n", mystrlen(s1), mystrlen(s2));
  printf("%d %d\n", myatoi('0'), myatoi('5'));
  printf("%d %d %d\n", htoi('0'), htoi('b'), htoi('A'));

}
