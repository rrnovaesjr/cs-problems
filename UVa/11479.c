#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main(void) {
	ull a, b, c;
	ull n, i;
	scanf("%llu", &n);
	for(i = 1; i <= n; i++) {
		scanf("%llu %llu %llu", &a, &b, &c);
		printf("Case %llu: ", i); 
		if(a < 0 || b < 0 || c < 0)
			printf("Invalid\n");
		else if(a + b <= c || a + c <= b || b + c <= a)
			printf("Invalid\n");
		else if(a == b && a == c && b == c)
			printf("Equilateral\n");
		else if(a != b && a != c && b != c)
			printf("Scalene\n");
		else
			printf("Isosceles\n");
	}
	return 0;
}