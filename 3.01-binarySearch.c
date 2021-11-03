#include <stdio.h>
#include <stdint.h>

#define SIZE 2000000

int binsearch(uint32_t arr[], uint32_t len, int x) {
  uint32_t low = 0;
  uint32_t hi = len - 1;
  uint32_t mid = (low + hi)/2;
  //uint32_t index
  while (low <= hi) {
    mid = (low + hi)/2;
    if (x < arr[mid]) {
      hi = mid - 1;
    } else if (x > arr[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  uint32_t arr[SIZE];
  for(int i = 0; i < SIZE; i++) {
    arr[i] = i;
  }
  printf("-1 = %d\n", binsearch(arr, SIZE, -2));
  printf("100 = %d\n", binsearch(arr, SIZE, 100));
  printf("0 = %d\n", binsearch(arr, SIZE, 0));
  printf("20000 = %d\n", binsearch(arr, SIZE, SIZE-1));
}
