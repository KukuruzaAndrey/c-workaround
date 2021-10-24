#include <stdio.h>

int contains(char c, char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

// remove all s2 chars from s1
void squeeze(char s1[], char s2[]) {
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') {
        if (!contains(s1[i], s2)) {
            s1[j] = s1[i];
            j++;
        }
        i++;
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "Kukuruza Andrey";
    char s2[] = "AKka";
    squeeze(s1, s2);
    printf("%s\n", s1);
}
