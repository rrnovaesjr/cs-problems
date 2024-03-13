#include <stdio.h>
#include <string.h>
#define MAXN 250000

typedef long long ll;

ll L[MAXN];

ll v[MAXN];

ll c;

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll f(ll i) {
	if(i == 1LL)
		return 0;
	
	if(L[i] != -1LL)
		return L[i];
	
	register ll j;

	L[i] = f(i - 1LL);
	for(j = 1LL; j < i; j++)
		L[i] = max(f(j) + (v[i] - v[j] - c), L[i]);
		
	return L[i];
}


int main(void) {
	ll n;
	
	scanf("%lld %lld", &n, &c);
	
	memset(L, -1LL, sizeof L);
	
	register ll i;
	for(i = 1LL; i <= n; i++) {
		scanf("%lld", &v[i]);
	}
	
	printf("%lld\n", f(n));

	return 0;
}
