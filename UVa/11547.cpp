#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, t;
	
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		n *= 567LL;
		n /= 9LL;
		n += 7492LL;
		n *= 235LL;
		n /= 47LL;
		n -= 498LL;
		
		n /= 10LL;
		n = (n % 10ll);
		printf("%lld\n", abs(n));
	
	}
	return 0;
}
