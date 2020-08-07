#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ciclo(ll n) {
	ll qCiclos = 1;
	
	while(n != 1LL) {
		if(n % 2LL == 0)
			n /= 2LL;
		else
			n = (3LL * n + 1LL);
		qCiclos++;
	}
	return qCiclos;
}

int main() {
	int i, j, li, lj;
	ll tCiclo;
	while(scanf("%d %d", &i, &j) == 2) {
		tCiclo = 0;
		if(i > j) {
			li = j;
			lj = i;
		}
		else {
			li = i;
			lj = j;
		}
		for(int k = li; k <= lj; k++)
			tCiclo = max(tCiclo, ciclo(k));
		printf("%d %d %lld\n", i, j, tCiclo);
	}
	return 0;
}
