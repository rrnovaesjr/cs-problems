
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10001
#define ALBERTO 0
#define WANDERLEY 1

typedef long long ull;

vector<ull> cards;

int N;

// The amount of cards in the left and the player
ull C[MAX_N][2];

ull calculate() {

	for (int l = 0; l < N - 1; l++)
		C[l][ALBERTO] = max(cards[l], cards[l + 1]);

	int player = ALBERTO;
	int lastPlayer = WANDERLEY;
	for (int k = 4; k <= N; k += 2) { //amount of available cards in game
		lastPlayer = player;
		player = !(player & 1);
		for (int l = 0, r = k - 1; r < N; l++, r++) { //moving left and right counters
			C[l][player] = max(
				cards[l] + min(C[l + 1][lastPlayer], C[l + 2][lastPlayer]),
				cards[r] + min(C[l][lastPlayer], C[l + 1][lastPlayer]));
		}	
	}
	
	return C[0][player];
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int u = 0; u < N; u++) {
			ull p;
			scanf("%llu", &p);
			cards.push_back(p);
		}
		printf("%llu\n", calculate());
		cards.clear();
	}

	return 0;
}
