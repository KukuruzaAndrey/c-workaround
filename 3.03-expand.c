#include <stdio.h>
#include <ctype.h>

#define len(arr) ((sizeof arr)/(sizeof arr[0]))

/* expand string with a-g 8-3 ranges s2 to s1 */
int in = 0;

char *putRange(char start, char end, char *dest) {
    if (end > start) {
        for (int i = 0; i <= end - start; ++i) {
            dest[i] = start + i;
        }
        return dest + end - start + 1;
    } else {
        for (int i = 0; i <= start - end; ++i) {
            dest[i] = start - i;
        }
        return dest + start - end + 1;
    }
}

void expand(char *s1, char *s2) {
    unsigned i = 0;
    while (s2[i] != '\0') {
        if (isdigit(s2[i])) {
            if ((s2[i + 1] == '-') && isdigit(s2[i + 2])) {
                s1 = putRange(s2[i], s2[i + 2], s1);
                i += 3;
                continue;
            }
        }
        if (isupper(s2[i])) {
            if ((s2[i + 1] == '-') && isupper(s2[i + 2])) {
                s1 = putRange(s2[i], s2[i + 2], s1);
                i += 3;
                continue;
            }
        }
        if (islower(s2[i])) {
            if ((s2[i + 1] == '-') && islower(s2[i + 2])) {
                s1 = putRange(s2[i], s2[i + 2], s1);
                i += 3;
                continue;
            }
        }
        *s1 = s2[i];
        s1++;
        i++;
    }
    *s1 = '\0';
}

int main() {

    char *compressed[] = {"abcd", "a", "-sds", "a-z", "G-A", "7-0a-fA-N", "abcd-a", "-7-1-a-c", "a-a"};
    char s1[100];
//    putRange('0', '9', s1);
    for (int i = 0; i < len(compressed); ++i) {
        expand(s1, compressed[i]);
        printf("%s - %s\n", compressed[i], s1);
    }
}

