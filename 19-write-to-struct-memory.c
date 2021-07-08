#include "stdio.h"
#include "string.h"

struct st {
    int a;
    int b;
};

int main() {
    struct st c;
    struct st *pointer = &c;
    printf("%p %ld\n", pointer, sizeof(pointer));
    char *p = (char *) pointer;
    printf("%p %ld\n", p, sizeof(p));

    c = (struct st) {10, 2};
    printf("%d %d\n", c.a, c.b);
    for (int i = 0; i < 8; ++i) {
        printf("%d\n", *(p+i));
    }
    printf("%p %ld\n", p, sizeof(p));
    char src[] = "dUdU";
    memcpy (p, src, 4);



    printf("%p %ld\n", p, sizeof(p));
    printf("%d %d\n", c.a, c.b);
    for (int i = 0; i < 8; ++i) {
        printf("%d\n", *(p+i));
    }

//    printf("=============\n");
//    int x = 1, y, z = 3;
//    int *p, *q;
//
//    p = &x;
//    printf("%d\n", *p); // 1
//
//    y = *p;
//    printf("%d\n", y); // 1
//
//    *p = 0;
//    printf("%d %d\n", x, y); // 0 1
//
//    q = &z;
//    printf("%d\n", *q); // 3
//
//    p = q;
//    *p = 4;
//    printf("%d\n", z); // 4
//
//    printf("%p %p\n", p, q); // p == q
}
