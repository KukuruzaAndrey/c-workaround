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
  char command_ID;
  int length;
  char data[18];
};

struct parser* parser;

int parse(char input) {
  switch(parser->st) {
    case SEARCHING_START:
      if (input == '[') {
        parser->state = SEARCHING_CMD;
      }
      break;
    
  }
}
int main() {
  
}
