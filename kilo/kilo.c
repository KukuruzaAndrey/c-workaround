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

int main() {
    enableRawMode();

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
    return 0;
}
