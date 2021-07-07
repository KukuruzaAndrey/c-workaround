#include "stdio.h"
#include "string.h"

struct st {
    int a;
    int b;
};

int main() {
    struct st c;
    c = (struct st) {1, 2};
    printf("%d %d\n", c.a, c.b);
    struct st *pointer = &c;
    char *p = (char *) pointer;
    for (int i = 0; i < 8; ++i) {
        char byte = *p;
        printf("%d\n", byte);
        p++;
    }
    *p = 0xAF;
    printf("%d %d\n", c.a, c.b);
    *p = (char *) pointer;
    for (int i = 0; i < 8; ++i) {
        char byte = *p;
        printf("%d\n", byte);
        p++;
    }
}
