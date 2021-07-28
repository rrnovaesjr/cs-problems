/*#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10001
#define ALBERTO 0
#define WANDERLEY 1

// The cards index at left, right and the players
int C[MAX_N][MAX_N];

vector<int> cards;

int N;

int calculate() {
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			C[j][i] = 0;

	int p = WANDERLEY;
	for (int l = 0; l < N - 1; l++) {
		for (int r = l + 1; r < N; r++) {	
			if (p == WANDERLEY) {
				C[l][r] = min( C[l + 1][r], C[l][r - 1] );
			} else {
				C[l][r] = max( C[l + 1][r] + cards[l], C[l][r - 1] + cards[r] );
			}
			p = (p + 1) % 2;			
		}
	}
	
	return C[0][N - 1];
}


int main() {
	while (scanf("%d", &N) == 1) {
		for (int u = 0; u < N; u++) {
			int p;
			scanf("%d", &p);
			cards.push_back(p);
		}
		printf("%d\n", calculate());
		cards.clear();
	}

	return 0;
}*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10001
#define ALBERTO 0
#define WANDERLEY 1

typedef unsigned long long ull;


// The cards index at left, right and the players
ull C[MAX_N][MAX_N];

vector<ull> cards;

int N;


ull calculate(int l, int r, int p) {	
	if (C[l][r] != -1)
		return C[l][r];
		
	if (l > r)
		return C[l][r] = 0;
	
	const int nextPlayer = (p + 1) % 2;
	
	if (p == WANDERLEY) {
		return (C[l][r] = min( 
			calculate(l + 1, r, nextPlayer),
			calculate(l, r - 1, nextPlayer)));
	}
	
	return (C[l][r] = max(
		calculate(l + 1, r, nextPlayer) + cards[l],
		calculate(l, r - 1, nextPlayer) + cards[r]));
}


int main() {
	while (scanf("%d", &N) == 1) {
		for (int u = 0; u < N; u++) {
			ull p;
			scanf("%llu", &p);
			cards.push_back(p);
		}
		for (int l = 0; l < N; l++)
			for (int r = 0; r < N; r++)
				C[l][r] = -1;
		printf("%llu\n", calculate(0, N - 1, ALBERTO));
		cards.clear();
	}

	return 0;
}
