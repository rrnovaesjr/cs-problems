#include <stdio.h>

typedef long long ll;

int main() {
	ll v, t;
	
	while(scanf("%lld %lld", &v, &t) == 2) {
		printf("%lld\n", 2 * t * v);
	}
	
	return 0;
}
