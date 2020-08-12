#include <stdio.h>
#include <math.h>

unsigned long long int calculate (int val) {
	return (unsigned long long int) ((pow(2, val)-1)/12000);
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
