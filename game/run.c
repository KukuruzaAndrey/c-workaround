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
void left();
void up();
void right();
void down();
struct pos pl;
int main() {
  ioctl(0, TIOCGWINSZ, &w);
  int tw = w.ws_col;
  int th = w.ws_row;

  tcgetattr(fileno(stdin), &term);

  int c, c1, c2;
  off();
  struct pos pl = {.x = 5, .y = 10};
  while((c=getchar())!=EOF) {
render(tw, th);
  if (c == 27) {
    c1 = getchar();
    if (c1 == '[') {
      c2 = getchar();
      switch (c2) {
        case 'D': 
          left();
          break;
        case 'A': 
          up();
          break;
        case 'C': 
          right();
          break;
        case 'B': 
          down();
          break;
        default:
          break;
      }
      
    }
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


void left() {
  printf("left");
  pl.x-=1;
}
void up() {
  printf("up");
pl.y+=1;
}
void right()  {

pl.x+=1;
  printf("right");
}
void down()  {
  printf("down");
pl.y-=1;
}

