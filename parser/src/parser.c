#include "parser.h"


PARSER_STATE_T state = SEARCHING_START;
int data_index = 0;

int Parser_AddChar(char input, struct packet *packet) {
  if (input == '[') {
    state = SEARCHING_CMD;
    return 0;
  }

  switch (state) {
    case SEARCHING_CMD:
      if (input >= 'A' && input <= 'Z') {
        packet->cmd = input;
        state = SEARCHING_LEN;
      } else {
        state = SEARCHING_START;
      }
      break;
    case SEARCHING_LEN:
      if (input == '0') {
        state = SEARCHING_END;
        packet->length = 0;
        break;
      }
      if (input > '0' && input <= '9') {
        packet->length = input - '0';
        data_index = 0;
        state = SEARCHING_DATA;
        break;
      }
      state = SEARCHING_START;
      break;
    case SEARCHING_DATA:
      if ((input >= '0' && input <= '9') ||
          (input >= 'a' && input <= 'f') ||
          (input >= 'A' && input <= 'F')) {
        int remain_bytes = 2 * packet->length - data_index;
        if (remain_bytes > 1) {
          packet->data[data_index] = input;
          data_index += 1;
        } else if (remain_bytes == 1) {
          packet->data[data_index] = input;
          state = SEARCHING_END;
        } else {
          state = SEARCHING_END;
        }
      } else {
        state = SEARCHING_START;
      }
      break;
    case SEARCHING_END:
      if (input == ']') {
        return 1;
      } else {
        state = SEARCHING_START;
      }
      break;
    default:
      state = SEARCHING_START;
  }
  return 0;
}
