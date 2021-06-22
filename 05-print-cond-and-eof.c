#include <stdio.h>

int main(){
  printf("true - %d, false - %d, EOF - %d\n",
           1 != 2, 1 == 2, EOF);
  printf("!0 - %d, !1 - %d", !0, !1);
}
