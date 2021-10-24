#include <stdio.h>
#include "parser.h"
#include "unity.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

extern PARSER_STATE_T state;
struct packet packet;


void print_packet(struct packet *packet) {
  printf("command - %c, len - %d, data - %.*s\n", packet->cmd, packet->length, packet->length * 2, packet->data);
}

void test_Parser_AddChar_should_StartLookingForCmdOnLeftBracket(void) {
  state = SEARCHING_START;

  TEST_ASSERT_FALSE(Parser_AddChar('[', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_CMD, state);
//  char input_stream[] = "[A3121212]";
//  for (int i = 0; i < ARRAY_SIZE(input_stream); i++) {
//    Parser_AddChar(input_stream[i], &packet);
//  }
//  print_packet(&packet);
}

void test_Parser_AddChar_should_RejectNonBracketCharacterWhileSeekingStart(void) {
  state = SEARCHING_START;

  TEST_ASSERT_FALSE(Parser_AddChar('|', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);
  TEST_ASSERT_FALSE(Parser_AddChar('A', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);
  TEST_ASSERT_FALSE(Parser_AddChar('F', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);
  TEST_ASSERT_FALSE(Parser_AddChar(']', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);
//  char input_stream[] = "[A3121212]";
//  for (int i = 0; i < ARRAY_SIZE(input_stream); i++) {
//    Parser_AddChar(input_stream[i], &packet);
//  }
//  print_packet(&packet);
}

void test_Parser_AddChar_should_AcceptValidCmd(void) {

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('A', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_LEN, state);

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('F', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_LEN, state);

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('Z', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_LEN, state);
}

void test_Parser_AddChar_should_RejectNonValidCommandCharacterWhileSeekingCommand(void) {

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('|', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('@', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('2', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar(']', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_CMD;
  TEST_ASSERT_FALSE(Parser_AddChar('a', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);
}

void test_Parser_AddChar_should_AcceptLength0(void) {
  state = SEARCHING_LEN;
  TEST_ASSERT_FALSE(Parser_AddChar('0', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_END, state);
}

void test_Parser_AddChar_should_RejectNonValidLengthWhileSeekingLength(void) {
  state = SEARCHING_LEN;
  TEST_ASSERT_FALSE(Parser_AddChar('|', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_LEN;
  TEST_ASSERT_FALSE(Parser_AddChar('@', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_LEN;
  TEST_ASSERT_FALSE(Parser_AddChar(']', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);

  state = SEARCHING_LEN;
  TEST_ASSERT_FALSE(Parser_AddChar('a', &packet));
  TEST_ASSERT_EQUAL(SEARCHING_START, state);
}

void insert_valid_minimal_packet(char cmd, struct packet *actual, struct packet *expected) {
  TEST_ASSERT_FALSE(Parser_AddChar('[', actual));
  TEST_ASSERT_FALSE(Parser_AddChar(cmd, actual));
  TEST_ASSERT_FALSE(Parser_AddChar('0', actual));
  TEST_ASSERT(Parser_AddChar(']', actual));
  TEST_ASSERT_EQUAL(expected->cmd, actual->cmd);
  TEST_ASSERT_EQUAL(expected->length, actual->length);
}

void insert_valid_standard_packet(char cmd, int length, char *data, struct packet *actual, struct packet *expected) {
  TEST_ASSERT_FALSE(Parser_AddChar('[', actual));
  TEST_ASSERT_FALSE(Parser_AddChar(cmd, actual));
  TEST_ASSERT_FALSE(Parser_AddChar('0' + length, actual));
  for (int i = 0; i < length * 2; i++) {
    TEST_ASSERT_FALSE(Parser_AddChar(data[i], actual))
  }
  TEST_ASSERT(Parser_AddChar(']', actual));
  TEST_ASSERT_EQUAL(expected->cmd, actual->cmd);
  TEST_ASSERT_EQUAL(expected->length, actual->length);
  TEST_ASSERT_EQUAL_MEMORY(expected->data, actual->data, length);
}

void test_Parser_AddChar_should_HandleValidPacketWithNoData(void) {
  state = SEARCHING_START;

  struct packet expected = {.cmd = 'A', .length=0, .data = {}};
  struct packet actual;
  insert_valid_minimal_packet('A', &actual, &expected);
}

void test_Parser_AddChar_should_IgnoreBadStartCharacters(void) {
  state = SEARCHING_START;

  struct packet expected = {.cmd = 'D', .length=0, .data = {}};
  struct packet actual;
  TEST_ASSERT_FALSE(Parser_AddChar('?', &actual));
  insert_valid_minimal_packet('D', &actual, &expected);

  state = SEARCHING_START;
  expected.cmd = 'X';
  expected.length = 0;
  TEST_ASSERT_FALSE(Parser_AddChar('a', &actual));
  TEST_ASSERT_FALSE(Parser_AddChar(']', &actual));
  insert_valid_minimal_packet('X', &actual, &expected);
}

void test_Parser_AddChar_should_HandleValidPacketWithDataLength1(void) {
  state = SEARCHING_START;
  struct packet expected = {.cmd = 'A', .length=1, .data = "AA"};
  struct packet actual;
  insert_valid_standard_packet('A', 1, "AA", &actual, &expected);
}

void test_Parser_AddChar_should_HandleValidPacketWithDataLength9(void) {
  state = SEARCHING_START;
  struct packet expected = {.cmd = 'A', .length=9, .data = "001122334455667788"};
  struct packet actual;
  insert_valid_standard_packet('A', 9, "001122334455667788", &actual, &expected);
}


int main() {
  UNITY_BEGIN();
  RUN_TEST(test_Parser_AddChar_should_StartLookingForCmdOnLeftBracket);
  RUN_TEST(test_Parser_AddChar_should_RejectNonBracketCharacterWhileSeekingStart);
  RUN_TEST(test_Parser_AddChar_should_AcceptValidCmd);
  RUN_TEST(test_Parser_AddChar_should_RejectNonValidCommandCharacterWhileSeekingCommand);
  RUN_TEST(test_Parser_AddChar_should_AcceptLength0);
  RUN_TEST(test_Parser_AddChar_should_RejectNonValidLengthWhileSeekingLength);
  RUN_TEST(test_Parser_AddChar_should_HandleValidPacketWithNoData);
  RUN_TEST(test_Parser_AddChar_should_IgnoreBadStartCharacters);
  RUN_TEST(test_Parser_AddChar_should_HandleValidPacketWithDataLength1);
  RUN_TEST(test_Parser_AddChar_should_HandleValidPacketWithDataLength9);
  return UNITY_END();
}