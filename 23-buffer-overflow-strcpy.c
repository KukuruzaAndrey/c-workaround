#include <stdio.h>
#include <string.h>

int main() {
	char           A[8] = "";
	unsigned short B    = 1979;
	printf("A: %s, B: %d/n", A, B);
	strcpy(A, "excessive");
	printf("A: %s, B: %d/n", A, B);
	return 0;
}
