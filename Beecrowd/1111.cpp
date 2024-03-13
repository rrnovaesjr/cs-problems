#include <bits/stdc++.h>
#define MAX_N (110)

using namespace std;

int N;

vector<int> graph[MAX_N];

int minDistance[MAX_N][MAX_N];

void bfs (int s) {
	queue<int> Q;
	Q.push(s);
	minDistance[s][s] = 0;
	int u;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int v : graph[u]) {
			if (minDistance[s][v] == -1) { 
				minDistance[s][v] = minDistance[s][u] + 1;
				Q.push(v);
			}
		}
	}
}

inline bool should_connect (int reference, int direction) {
	return reference + direction < N && reference + direction >= 0;
}

inline int get_square_index (int x, int y) {
	return x * N + y;
}

int main() {
	int P, x, y, w, z, path;

	while (scanf("%d", &N) == 1 && N) {

		for (int i = 0; i < N*N; i++) {
			for (int j = 0; j < N*N; j++) {
				minDistance[i][j] = -1;
			}
		}

		for (int street = N - 1; street >= 0; street--) {
			for (int square = 0; square < N; square++) {
				for (int vertical = 1; vertical >= -1; vertical -= 2) {
					scanf("%d", &path);
					if (should_connect(street, vertical) && path) {
						graph[get_square_index(street,square)].push_back(get_square_index(street + vertical, square));
					}
				}

				for (int horizontal = -1; horizontal <= 1; horizontal += 2) {
					scanf("%d", &path);
					if (should_connect(square, horizontal) && path) {
						graph[get_square_index(street,square)].push_back(get_square_index(street, square + horizontal));
					}
				}
			}
		}

		for (int u = 0; u < N*N; u++) {
			bfs (u);
		}

		scanf("%d", &P);;

		while (P--) {
			scanf("%d %d %d %d", &x, &y, &w, &z);
			int dist = minDistance[get_square_index(y,x)][get_square_index(z,w)];
			if (dist != -1) {
				printf("%d\n", dist);
			} else {
				printf("Impossible\n");
			}
		}

		for (int u = 0; u < N*N; u++) {
			graph[u].clear();
		}

		printf("\n");

	}
	
	return 0;
}



