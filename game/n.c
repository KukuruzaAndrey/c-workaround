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

int getWindowSize(struct winsize *ws) {
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, ws) == -1 || ws->ws_col == 0) {
        return -1;
    } else {
        return 0;
    }
}

struct winsize ws;
struct pos {
    unsigned x;
    unsigned y;
};
struct pos pl;


void render() {
    for (unsigned y = 0; y < ws.ws_row; y++) {
        for (unsigned x = 0; x < ws.ws_col; x++) {
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

char editorReadKey() {
    int nread;
    char c;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        if (nread == -1 && errno != EAGAIN) die("read");
    }
    return c;
}

void editorProcessKeypress() {
    char c = editorReadKey();
    switch (c) {
        case CTRL_KEY('q'):
            exit(0);
            break;
    }
}

int main() {
    enableRawMode();
    getWindowSize(&ws);

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

        render();
    }
}
