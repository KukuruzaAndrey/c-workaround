#include <stdio.h>
#include <termios.h>

int main(int argc, char *argv[])
{
    printf("Enter password: ");

    struct termios term;
    tcgetattr(fileno(stdin), &term);

    term.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), 0, &term);

    char passwd[32];
    fgets(passwd, sizeof(passwd), stdin);

    term.c_lflag |= ECHO;
    tcsetattr(fileno(stdin), 0, &term);

    printf("\nYour password is: %s\n", passwd);
}
