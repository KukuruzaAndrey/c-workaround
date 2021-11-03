#include "stdint.h"
#include "buffer.h"

#define BUFFER_SIZE (1000+1)

uint16_t buffer[BUFFER_SIZE];

int read_p = 0;
int write_p = 0;

void init() {
  read_p = 0;
  write_p = 0;
}

error_t write(uint16_t e) {
  uint16_t NextWrite = (write_p + 1) % BUFFER_SIZE;
  if (NextWrite == read_p)
    return WRITING_TO_FULL;
  buffer[write_p] = e;
  write_p = NextWrite;
  return OK;
}

error_t read(uint16_t *e) {
  if (read_p >= BUFFER_SIZE) read_p = 0;
  if (read_p == write_p)
    return READING_FROM_EMPTY;
  *e = buffer[read_p];
  read_p = (read_p + 1) % BUFFER_SIZE;
  return OK;
}

int is_full() {
  uint16_t NextWrite = (write_p + 1) % BUFFER_SIZE;
  return NextWrite == read_p;
}

int is_empty() {
  return write_p == read_p;
}

void clear() {
  read_p = 0;
  write_p = 0;
}