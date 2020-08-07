#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
	ll n, g;
	
	while(scanf("%lld", &n), n) {
		do {
			g = 0LL;
			do {
				g += (n % 10LL);
				n /= 10LL;
			} while(n > 0LL);
			n = g;
		} while(n / 10LL > 0LL);
		printf("%lld\n", n);
	}
	return 0;
}
