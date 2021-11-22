#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios original;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &original);
    atexit(disableRawMode);

    struct termios raw = original;
    raw.c_iflag &= ~(ICRNL | IXON);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

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
    enableRawMode();
  ioctl(0, TIOCGWINSZ, &w);
  int tw = w.ws_col;
  int th = w.ws_row;

  //tcgetattr(fileno(stdin), &term);

  int c, c1, c2;
  struct pos pl = {.x = 5, .y = 10};

    char c;
    while (1) {
        c = '\0';
        read(STDIN_FILENO, &c, 1);
        if (iscntrl(c)) {
            printf("%d\n", c);
        } else {
            printf("%d ('%c')\n", c, c);
        }
        if (c == 'q') break;
    }


  while((c=getc(stdin))!=EOF) {
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
    }

//printf("%d",c);    
//putchar(c);
  }  
  
	  //render(tw, th);
}

void render(int tw, int th) {
  for (int y = 0; y < th; y++) {
    for (int x = 0; x < tw; x++) {
      if (x == pl.x && y == pl.y) putchar('@');
      else 
      putchar(' ');
    }
    putchar('\n');
  }
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
