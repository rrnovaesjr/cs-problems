#include <stdio.h>

unsigned long long int calculate (int val) {
	val--;
	return (((1ULL << val)-1ULL)/6000ULL);
}

int main() {
	int N;
	int X;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		printf("%llu kg\n", calculate (X));
	}
	return 0;
}
