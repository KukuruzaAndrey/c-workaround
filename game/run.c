#include "stdio.h"
#include <termios.h>

#include <sys/ioctl.h>

void render();
// detect terminal width
struct winsize w;
//printf("%d\n", w.ws_col);
struct pos {
  unsigned x;
  unsigned y;
};
struct termios term;
void on();
void off();

int main() {
  ioctl(0, TIOCGWINSZ, &w);
  int tw = w.ws_col;
  int th = w.ws_row;

  tcgetattr(fileno(stdin), &term);

  int c;
  off();
  while((c=getchar())!=EOF) {
  if (c == 0) {
    char c1 = getchar();
    printf("\n\n%d", c1+255);
  } else
printf("%d",c);    
//putchar(c);
  };  
  on();
  render(tw, th);
}

void render(int tw, int th) {
  for (int y = 0; y < th; y++) {
    for (int x = 0; x < tw; x++) {
      if (x == 5 && y == 10) putchar('@');
      else 
      putchar(' ');
    }
    putchar('\n');
  }
}


void on() {
    term.c_lflag |= ECHO;
    tcsetattr(fileno(stdin), 0, &term);
}

void off() {
    term.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), 0, &term);
}

