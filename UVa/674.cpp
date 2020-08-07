#include <bits/stdc++.h>
#define MAXC 8900
#define NCOINS 6

using namespace std;

int S[NCOINS] = {0, 1, 5, 10, 25, 50};

int pd[MAXC][NCOINS];

int f(int n, int m) {
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	if(m <= 0 && n >= 1)
		return 0;
	
	int &p = pd[n][m];
	
	if(p != -1)
		return p;

	p = f(n, m - 1) + f(n - S[m], m);	
	return p;
}

int main() {	
	int n;
	memset(pd, -1, sizeof pd); 
	while(scanf("%d", &n) == 1) {
		printf("%d\n", f(n, NCOINS - 1));
	}
	return 0;
}
