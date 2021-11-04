#include <stdio.h>
#include <ctype.h>

#define len(arr) ((sizeof arr)/(sizeof arr[0]))

/* expand string with a-g 8-3 ranges s2 to s1 */
int in = 0;

char *putRange(char start, char end, char *dest) {
    unsigned len = (end > start) ? end - start : start - end;
    int sign = (end > start) ? 1 : -1;
    unsigned i = 0;
    while (i <= len) {
        *(dest++) = start + i * sign;
        i++;
    }
    return dest;

}

unsigned isRange(char *start) {
    return (isdigit(*start) && (*(start + 1) == '-') && isdigit(*(start + 2))) ||
           (isupper(*start) && (*(start + 1) == '-') && isupper(*(start + 2))) ||
           (islower(*start) && (*(start + 1) == '-') && islower(*(start + 2)));
}

void expand(char *s1, char *s2) {
    while (*s2 != '\0') {
        if (isRange(s2)) {
            s1 = putRange(*s2, *(s2 + 2), s1);
            s2 += 3;
            continue;
        }
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int main() {

    char *compressed[] = {"abcd", "a", "-sds", "a-z", "G-A", "7-0a-fA-N", "abcd-a",
                          "-7-1-a-c", "a-a", "a-0-6b--pq-w9-0-3"};
    char s1[100];
    for (int i = 0; i < len(compressed); ++i) {
        expand(s1, compressed[i]);
        printf("%s - %s\n", compressed[i], s1);
    }
}

