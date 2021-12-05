#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(void) {

    return execl("./test.js", "node", "5", NULL);

}