#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

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
    raw.c_cc[VTIME] = 10;
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

//    int c, c1, c2;
    struct pos pl = {.x = 5, .y = 10};

    char c;
    while (1) {
        read(STDIN_FILENO, &c, 1);
        if (c == '\x1b') {
            char seq[3];
            read(STDIN_FILENO, &seq[0], 1);
            read(STDIN_FILENO, &seq[1], 1);
            if (seq[0] == '[') {
                switch (seq[1]) {
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
//        return '\x1b';
        } else if (c == 'q') {
            return 0;
//        return c;
        }

        render(tw, th);
    }
}

void render(int tw, int th) {
    for (int y = 0; y < th; y++) {
        for (int x = 0; x < tw; x++) {
            if (x == pl.x && y == pl.y) putchar('@');
            else
                putchar(' ');
        }
        putchar('\r');
        putchar('\n');
    }
}


void left() {
//    printf("left");
    pl.x -= 1;
}

void up() {
//    printf("up");
    pl.y -= 1;
}

void right() {
    pl.x += 1;
//    printf("right");
}

void down() {
//    printf("down");
    pl.y += 1;
}
