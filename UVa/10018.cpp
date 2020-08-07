#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, m, x, add, t, op;
	scanf("%lld", &t);
	
	int i = 0;
	while(t--) {
		scanf("%lld", &n);
	
		op = 0LL;
		while(true) {
			x = n;
			m = 0LL;
			i = (int) (log(x)/log(10));
			while(i >= 0) {
				m += (ll) ((x % 10LL) * pow(10LL, i));
				i--;
				x /= 10LL;	
			}
			if(n == m)
				break;
			n += m;
			op++;
		};
		printf("%lld %lld\n", op, n);
	}
	
	
	return 0;
}
