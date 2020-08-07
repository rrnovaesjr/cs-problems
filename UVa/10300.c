#include <stdio.h>

int main() {
	int n, s, a, f, i, t;
	int total;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		total = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &s, &a, &f);
			total += (s * f);
		}
		printf("%d\n", total);
	}
	return 0;
}
