#include <unity.h>
#include "stdint.h"
#include "buffer.h"

#define BUFFER_SIZE 1000

void setUp(void) {
  init();
}

void write_full_buffer() {
  for (int i = 0; i < BUFFER_SIZE; ++i) {
    TEST_ASSERT_EQUAL(OK, write(i));
  }
}

void test_Read_should_Read_one_element_after_Write(void) {
  int count = 4;
  uint16_t fetched;
  uint16_t es[] = {0xABAB, 0x1, 0xbaba, 0xFACA};
  for (int i = 0; i < count; ++i) {
    TEST_ASSERT_EQUAL(OK, write(es[i]));
    TEST_ASSERT_EQUAL(OK, read(&fetched));
    TEST_ASSERT_EQUAL(es[i], fetched);
  }
}

void test_FIFO_must_work_through_buffer_size(void) {
  uint16_t fetched;
  // write full buffer
  write_full_buffer();

  // read half of it
  for (int i = 0; i < BUFFER_SIZE / 2; ++i) {
    TEST_ASSERT_EQUAL(OK, read(&fetched));
    TEST_ASSERT_EQUAL(i, fetched);
  }

  // write free half space
  for (int i = BUFFER_SIZE; i < BUFFER_SIZE + BUFFER_SIZE / 2 - 1; ++i) {
    TEST_ASSERT_EQUAL(OK, write(i));
  }

  // read full buffer
  for (int i = BUFFER_SIZE / 2; i < BUFFER_SIZE + BUFFER_SIZE / 2 - 1; ++i) {
    TEST_ASSERT_EQUAL(OK, read(&fetched));
    TEST_ASSERT_EQUAL(i, fetched);
  }
}

void test_is_full_on_empty_buffer() {
  TEST_ASSERT_FALSE(is_full())
}

void test_is_full_on_half_empty_buffer() {
  for (int i = 0; i < BUFFER_SIZE / 2; ++i) {
    TEST_ASSERT_EQUAL(OK, write(i));
  }

  uint16_t fetched;
  for (int i = 0; i < BUFFER_SIZE / 4; ++i) {
    TEST_ASSERT_EQUAL(OK, read(&fetched));
    TEST_ASSERT_EQUAL(i, fetched);
  }
  TEST_ASSERT_FALSE(is_full())
}

void test_is_full_on_full_buffer() {
  write_full_buffer();

  TEST_ASSERT(is_full())
}


void test_reading_from_empty() {
  uint16_t fetched;
  TEST_ASSERT_EQUAL(READING_FROM_EMPTY, read(&fetched));
}

void test_reading_from_empty_after_write_read() {
  uint16_t fetched;
  for (int i = 0; i < BUFFER_SIZE / 2; ++i) {
    TEST_ASSERT_EQUAL(OK, write(i));
  }

  for (int i = 0; i < BUFFER_SIZE / 2; ++i) {
    TEST_ASSERT_EQUAL(OK, read(&fetched));
    TEST_ASSERT_EQUAL(i, fetched);
  }

  TEST_ASSERT_EQUAL(READING_FROM_EMPTY, read(&fetched));
}

void test_write_to_full_buffer() {
  write_full_buffer();

  TEST_ASSERT_EQUAL(WRITING_TO_FULL, write(1));
}

void test_is_empty_on_empty_buffer() {
  TEST_ASSERT(is_empty())
}

void test_is_empty_on_half_empty_buffer() {
  for (int i = 0; i < BUFFER_SIZE / 2; ++i) {
    TEST_ASSERT_EQUAL(OK, write(i));
  }

  uint16_t fetched;
  for (int i = 0; i < BUFFER_SIZE / 4; ++i) {
    TEST_ASSERT_EQUAL(OK, read(&fetched));
    TEST_ASSERT_EQUAL(i, fetched);
  }
  TEST_ASSERT_FALSE(is_empty())
}

void test_is_empty_on_full_buffer() {
  write_full_buffer();

  TEST_ASSERT_FALSE(is_empty())
}

void test_clear_on_start() {
  clear();
  write_full_buffer();
}

void test_clear_on_full_buffer() {
  write_full_buffer();
  clear();
  write_full_buffer();
}


int main() {
  UNITY_BEGIN();
  RUN_TEST(test_Read_should_Read_one_element_after_Write);
  RUN_TEST(test_FIFO_must_work_through_buffer_size);
  RUN_TEST(test_is_full_on_empty_buffer);
  RUN_TEST(test_is_full_on_half_empty_buffer);
  RUN_TEST(test_is_full_on_full_buffer);
  RUN_TEST(test_reading_from_empty);
  RUN_TEST(test_reading_from_empty_after_write_read);
  RUN_TEST(test_write_to_full_buffer);
  RUN_TEST(test_is_empty_on_empty_buffer);
  RUN_TEST(test_is_empty_on_half_empty_buffer);
  RUN_TEST(test_is_empty_on_full_buffer);
  RUN_TEST(test_clear_on_start);
  RUN_TEST(test_clear_on_full_buffer);
  return UNITY_END();
}