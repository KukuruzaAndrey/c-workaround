#include <stdio.h>
#include <ctype.h>

int main()
{
    int a;
    typedef struct {
        int b7 : 1;
        int b6 : 1;
        int b5 : 1;
        int b4 : 1;
        int b3 : 1;
        int b2 : 1;
        int b1 : 1;
        int b0 : 1;
    } byte;

    byte ab0 = {0,0,0,0,0,0,0,1};
    a = *(int*)&ab0;
    printf("ab0 is %x \n",a);

    byte ab1 = {0,0,0,0,0,0,1,0};
    a = *(int*)&ab1;
    printf("ab1 is %x \n",a);

    byte ab2 = {0,0,0,0,0,1,0,0};
    a = *(int*)&ab2;
    printf("ab2 is %x \n",a);

    byte ab3 = {0,0,0,0,1,0,0,0};
    a = *(int*)&ab3;
    printf("ab3 is %x \n",a);

    byte ab4 = {0,0,0,1,0,0,0,0};
    a = *(int*)&ab4;
    printf("ab4 is %x \n",a);

    byte ab5 = {0,0,1,0,0,0,0,0};
    a = *(int*)&ab5;
    printf("ab5 is %x \n",a);

    byte ab6 = {0,1,0,0,0,0,0,0};
    a = *(int*)&ab6;
    printf("ab6 is %x \n",a);

    byte ab7 = {1,0,0,0,0,0,0,0};
    a = *(int*)&ab7;
    printf("ab7 is %x \n",a);

    printf("%d\n", isdigit('a'));
    printf("%d\n", isdigit('0'));
    return 0;
}