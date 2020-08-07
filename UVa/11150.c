#include <stdio.h>

int main() {
	int N, total;
	while(scanf("%d", &N) == 1) {
		total = N;
		while(N >= 3) {
			total += N/3;
			N = N/3 + (N % 3);
		}
		if(N == 2)
			total++;
		printf("%d\n", total);
	}

	return 0;
}
