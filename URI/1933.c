#include <stdio.h>

typedef short si;

si max(si a, si b) {
	return a > b ? a : b;
} 

int main(void) {
	si a, b;
	scanf("%hd %hd", &a, &b);
	printf("%hd\n", max(a, b));
	return 0;
}
