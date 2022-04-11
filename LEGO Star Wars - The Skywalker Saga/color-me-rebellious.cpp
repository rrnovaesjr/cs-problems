#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define GOAL_1 0b1111111111111111111111111
#define GOAL_0 0b0000000000000000000000000

using namespace std;

int game = GOAL_0;

int goal;

struct state {
	int i;
	int j;
	int current_game;
	
	state() {}
	
	state(int current_game, int i, int j): i(i), j(j), current_game(current_game) {}
};

inline int IDX(int i, int j) {
	return i * 5 + j;
}

int sw(int v) {
	return !v;
}

inline int bit_at(int value, int i, int j) {
	int bitmask = 1 << IDX(i, j);
	return (value & bitmask) >> IDX(i, j);	
}

void doprintgame(int mygame) {
	int bitmask;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			bitmask = (1 << IDX(i, j));
			printf(" %d", bit_at(mygame, i, j) );
		}
		printf("\n");
	}
	printf("--------------\n");
}

void printgame() {
	doprintgame(game);
}


int jump_to(int current_game, int i, int j) {
	int nei = current_game;
	int bitmask;
	int value;
	for (int n = -1; n <= 1; n++) {
		if (n + i >= 0 && n + i < 5) {
			for (int m = -1; m <= 1; m++) {
				if (m + j >= 0 && m + j < 5) {
					bitmask = (1 << IDX(i + n, j + m));
					value = sw( bit_at(current_game, i + n, j + m) );
					nei = (nei & ~bitmask) | (value << IDX(i + n, j + m));
				}

			}
		}

	}
	bitmask = (1 << IDX(i, j));
	value = bit_at(current_game, i, j);
	nei = (nei & ~bitmask) | (value << IDX(i, j));
	return nei;
}

void generate_goal(int value) {
	if (value == 0) {
		goal = GOAL_0;
		return;
	}
	goal = GOAL_1;
}

vector<state> get_adj(int current_game, int u, int v) {
	vector<state> adj;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (IDX(i, j) != IDX(u, v)) {
				adj.push_back( state( jump_to(current_game, i, j), i, j) );
			}			
		}
	}
	return adj;
}

#ifndef XOR
int distance(const state &s1) {
	return abs( goal - s1.current_game );
}
#endif
#ifdef XOR
int distance(const state &s1) {
	return s1.current_game ^ goal;
}

#endif

struct cmp {

	bool operator()(const state &s1, const state &s2) const {
		return distance(s1) > distance(s2);
	}

};

void dj() {
	priority_queue<state, vector<state>, cmp> Q;
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			Q.push(state(jump_to( game, i, j), i, j ));
	
	int it = 1;
	while (Q.size() > 1) {
		auto u = Q.top();
		
		printf("%d: jumping to %d,%d\n", it++, u.i, u.j);
		#ifdef DEBUG
		doprintgame(u.current_game);
		#endif
		
		Q.pop();
	
		if (u.current_game == goal) break;

		auto adj = get_adj(u.current_game, u.i, u.j);

		for (auto v : adj) {
			Q.push(v); 
		}		
	}
}

int main() {
	int value, goal;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> value;
			game |= (value << IDX(i, j));
		}
	}
	printgame();
	cin >> goal;
	generate_goal(value);
	dj();
	return 0;
}
