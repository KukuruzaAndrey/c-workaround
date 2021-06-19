#include <stdio.h>

// return length of read line
int readline(char line[]);
void reverse(char line[], int length);

// char [] reverse2(char line[]);

int main() {
  char textline[100];
  int lineLength = readline(textline);
//  printf("%d %d %d", 3/2, 5/2, 5.0/2);
  while (lineLength != 0) {
  //  printf("%s\n", textline);
    reverse(textline, lineLength);
    printf("%s\n", textline);

    lineLength = readline(textline);
  }
}

int readline(char line[]) {
  int c = getchar();
  int i = 0;
  while (c != EOF && c != '\n') {
  //  printf("%d - %c=eof\n", c == EOF,c);
  //  printf("%d - %c=n\n", c == '\n',c);

    line[i] = c;
  //  printf("%c", c);
    i += 1;
    c = getchar();
  }
//  if (c == '\n') {
  //  printf("\\n\n");
//    line[i] = c;
//    i += 1;
//  }
  line[i] = '\0';
  return i;
}

//1	0	0
//2	1	1
//3	1	1
//4	2	2
//5	2
//6	3
//7	3
void reverse(char line[], int length) {
  char temp;
  for(int i = 0; i < length/2; i++) {
    temp = line[i];
  //  printf("switch %c and %c, %d\n", line[i], line[length - 1 - i], i);
    line[i] = line[length - 1 - i];
    line[length - 1 - i] = temp;
  }
}
