#include <stdio.h>

int main () {
  int c;
  int cNext;
  int insideStringLiteral = 0;
  int insideEscapeSequance = 0;
/////  int skipNextChar = 0;
//  int canStartInlineComment = 0;
  int insideInlineComment = 0;/*
  int canStartMultilineComment = 0;
  int canEndMultilineComment = 0;*/
  int insideMultilineComment = 0;
  int printSecondChar = 0;
  // dont forget about \"
  while ((c = getchar()) != EOF) {
    if (c == '\\') {
      insideEscapeSequance = 1;
    } else if (c == '"' && !insideEscapeSequance) {
      insideStringLiteral = !insideStringLiteral;
    } else if (c == '/' && !insideStringLiteral && !insideInlineComment && !insideMultilineComment) {
      cNext = getchar();
      if (cNext == '/') {
        insideInlineComment = 1;
      } else if (cNext == '*') {
        insideMultilineComment = 1;
//        canStartInlineComment = 1;
//        canStartMultilineComment = 1;
      } else {
        printSecondChar = 1;
      }
    } else if (c == '*' && !insideStringLiteral && !insideInlineComment) {
      cNext = getchar();
      if (cNext == '/') {
        insideMultilineComment = 0;
        continue;
      } else {
        printSecondChar = 1;
      }/** else {
        canEndMultilineComment = 1;*/
    } else if (c == '\n') {
      if (insideInlineComment == 1) {
        insideInlineComment = 0;
        continue;
      }
    }/* else {
      int canStartInlineComment = 0;
      int canStartMultilineComment = 0;
      int canEndMultilineComment = 0;
    }*/
    if (!insideInlineComment && !insideMultilineComment) {
      putchar(c);
      if (printSecondChar) {
        putchar(cNext);
        printSecondChar = 0;
      }
    }
  }
}
