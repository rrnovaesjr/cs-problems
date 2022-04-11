#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string game = "";

string goal;

struct state {
	int i;
	int j;
	string current_game;
	
	state() {}
	
	state(string current_game, int i, int j): i(i), j(j), current_game(current_game) {}
};

inline int IDX(int i, int j) {
	return i * 5 + j;
}

char sw(char v) {
	if (v == '1') return '0';
	return '1';
}

void doprintgame(string mygame) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf(" %c", mygame[IDX(i, j)]);
		}
		printf("\n");
	}
	printf("--------------\n");
}

void printgame() {
	doprintgame(game);
}


string jump_to(string current_game, int i, int j) {
	string nei = current_game;
	for (int n = -1; n <= 1; n++) {
		if (n + i >= 0 && n + i < 5) {
			for (int m = -1; m <= 1; m++) {
				if (m + j >= 0 && m + j < 5) {
					nei[IDX(i + n, j + m)] = sw(current_game[IDX(i + n, j + m)]); 	
				}

			}
		}

	}
	nei[IDX(i, j)] = current_game[IDX(i, j)];
	return nei;
}

void generate_goal(int value) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			goal.push_back(value + '0');
}

vector<state> get_adj(string current_game, int u, int v) {
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
	int dif = 0;
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++)
			if (s1.current_game[IDX(i, j)] != goal[IDX(i, j)])
				dif++;
	return dif;
}
#endif
#ifdef XOR
int distance(const state &s1) {
	int dif = 0;
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++)
			if (s1.current_game[IDX(i, j)] != goal[IDX(i, j)])
				dif += ((s1.current_game[IDX(i, j)] - '0') ^ (goal[IDX(i, j)] - '0')) << (IDX(i, j));
	return dif;
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
			game.push_back(value + '0');	
		}
	}
	printgame();
	cin >> goal;
	generate_goal(value);
	dj();
	return 0;
}
