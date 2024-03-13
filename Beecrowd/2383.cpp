#include <bits/stdc++.h>

using namespace std;

#define MAXN 350

int dp[MAXN][MAXN];

void initialize() {
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dp[i][j] = -1;
}

int L2(int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	if (n == 0 || k == 1) return (dp[n][k] = n);

	int min_tries = n;

	for (int i = 1; i <= n; i++) {
		min_tries = min(min_tries,          // minimizes current amount of tries
			1 + max( 		    // adds 1 to the worst case scenario			
				L2(i - 1, k - 1),   // balloon pops: needs to check all i - 1 cases again with
				L2(n - i, k)));     // balloon doesn't pop: can check only n - i cases
	}

	return (dp[n][k] = min_tries);
}

int L(int n, int k) {

	// Minimizes big values of N with small-ish Ks
	int min_tries = (int) ceil(log2(n));
	if (k >= min_tries) {
		return min_tries;
	}
	
	// For other values, compute as subproblems
	return L2(n, k);
}

int main() {
	initialize();
	int N, K;
	while(scanf("%d %d", &N, &K) == 2) {
		printf("%d\n", L(N, K));
	}
	return 0;
}
