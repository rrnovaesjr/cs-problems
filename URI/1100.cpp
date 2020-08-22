#include <bits/stdc++.h>
#define MAX_N 8

using namespace std;

inline int get_x (unsigned char ch) {
	return ch - 'a';
}

inline unsigned char unget_x (int x) {
	return x + 'a';
}

inline int get_y (unsigned int d) {
	return d - 1;
}

inline unsigned int unget_y (int d) {
	return d + 1;
}

vector<pair<unsigned char, unsigned int>> get_possible_cords (unsigned char ch, unsigned int d) {
	int x = get_x(ch);
	int y = get_y(d);
	vector<pair<unsigned char, unsigned int>> validMovements;
	
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if (abs(abs(i) - abs(j)) == 1 && (i && j) &&
				x + i >= 0 && x + i < MAX_N && 
				y + j >= 0 && y + j < MAX_N) {
				
				validMovements.push_back(make_pair(unget_x(x + i), unget_y(y + j)));
			}
		}
	}
	return validMovements;
}

int bfs (unsigned char x1, unsigned int y1, unsigned char x2, unsigned int y2) {
	
	queue<pair<unsigned char, unsigned int>> Q;
	
	Q.push( make_pair(x1, y1) );
	
	int dist[MAX_N][MAX_N];

	memset(dist, INT_MAX, sizeof dist);
	
	dist[get_x(x1)][get_y(y1)] = 0;
	while (!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		
		if (x2 == u.first && y2 == u.second) {
			break;
		}

		auto adj = get_possible_cords (u.first, u.second);
		
		for (auto v : adj) {
			if (dist[get_x(v.first)][get_y(v.second)] < INT_MAX) {
				dist[get_x(v.first)][get_y(v.second)] = dist[get_x(u.first)][get_y(u.second)] + 1;
				Q.push(v);
			}
		}
	}
	
	return dist[get_x(x2)][get_y(y2)];
}

int main() {
	unsigned char x1, x2;
	unsigned int y1, y2;
	
	while (scanf("%c%d %c%d\n", &x1, &y1, &x2, &y2) == 4) {
		printf("To get from %c%d to %c%d takes %d knight moves.\n", x1, y1, x2, y2, bfs(x1, y1, x2, y2));
	}	
	return 0;
}
