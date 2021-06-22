#include <stdio.h>

int main () {
  int c;
  int insideStringLiteral = 0;
  int insideEscapeSequance = 0;
  int skipNextChar = 0;
  int canStartInlineComment = 0;
  int insideInlineComment = 0;
  int canStartMultilineComment = 0;
  int canEndMultilineComment = 0;
  int insideMultilineComment = 0;
  // dont forget about \"
  while ((c = getchar()) != EOF) {
    if (c == '\\') {
      insideEscapeSequance = 1;
    } else if (c == '"' && !insideEscapeSequance) {
      insideStringLiteral = !insideStringLiteral;
    } else if (c == '/' && !insideEscapeSequance) {
      if (canStartInlineComment) {
        insideInlineComment = 1;
      } else if (canEndMultilineComment) {
        insideMultilineComment = 0;
      } else {
        canStartInlineComment = 1;
        canStartMultilineComment = 1;
      }
    } else if (c == '*' && !insideEscapeSequance) {
      if (canStartMultilineComment) {
        insideMultilineComment = 1;
      } else {
        canEndMultilineComment = 1;
      }
    } else if (c == '\n') {
      insideInlineComment = 0;
    } else {
      int canStartInlineComment = 0;
      int canStartMultilineComment = 0;
      int canEndMultilineComment = 0;
    }
    if (!insideInlineComment && !insideMultilineComment) {
      putchar(c);
    }
  }
}
