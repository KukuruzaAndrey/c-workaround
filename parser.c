#include <stdio.h>

enum state {
  SEARCHING_START,
  SEARCHING_CMD,
  SEARCHING_LEN,
  GETTING_DATA,
  SEARCHING_END
};

struct parser {
  enum state st;
  char cmd;
  int length;
  int data_index;
  char data[18];
};

struct parser* parser;

int parse(char input) {
  switch(parser->st) {
    case SEARCHING_START:
      if (input == '[') {
        parser->st = SEARCHING_CMD;
      }
      break;
    case SEARCHING_CMD:
      if (input >= 'A' && input <= 'Z') {
        parser->cmd = input;
        parser->st = SEARCHING_LEN;
      } else if (input == '[') {
        parser->st = SEARCHING_CMD;
      } else {
        parser->st = SEARCHING_START;
      }
      break;
    case SEARCHING_LEN:
      if (input >= '0' && input <= '9') {
        parser->length = input - '0';
        parser->data_index = 0;
        parser->st = GETTING_DATA;
      } else if (input == '[') {
        parser->st = SEARCHING_CMD;
      } else {
        parser->st = SEARCHING_START;
      }
      break;
    case GETTING_DATA:
      if ((input >= '0' && input <= '9') ||
          (input >= 'a' && input <= 'f') ||
          (input >= 'A' && input <= 'F')) {
        if (2*parser->length - parser->data_index >= 1) {
          parser->data[parser->data_index] = input;
          parser->data_index += 1;
          parser->state
        } el
        parser->length = input - '0';
        parser->st = GETTING_DATA;
      } else if (input == '[') {
        parser->st = SEARCHING_CMD;
      } else {
        parser->st = SEARCHING_START;
      }
      break;
  }
}
int main() {
  
}
