#include <bits/stdc++.h>
#define MAXN 500050
#define MAXL 15

using namespace std;

typedef long long ll;

struct edge {
	int v; 
	ll p;

	edge() {}

	edge(int a, ll b) {
		v = a;
		p = b;
	}
};

vector<edge> G[MAXN];

ll d[MAXN];

int pai[MAXN];

int nivel[MAXN];

int a[MAXN][MAXL];

void bfs(int s) {
	memset(pai, -1, sizeof pai);
	memset(nivel, -1, sizeof nivel);

	d[s] = 0LL;
	nivel[s] = 0;
	
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		
		for(int i = 0; i < G[u].size(); i++) {
			edge v = G[u][i];
			if(nivel[v.v] == -1) {
				pai[v.v] = u;
				nivel[v.v] = nivel[u] + 1;
				d[v.v] = d[u] + v.p;
				Q.push(v.v);
			}
		}
	
	}
}

int lca(int u, int v) {
	if(nivel[u] < nivel[v]) {
		swap(u, v);
	}
		/*
	for(int i = 1; nivel[u] != nivel[v]; i++) {
		if(nivel[ a[u][i] ] < nivel[v] || a[u][i] == -1) {
			u = a[u][i - 1];
			i = 0;
		}
	}
		*/
	/*	
	int n = MAXL - 1;
	while(nivel[u] != nivel[v]) {
		if(a[u][n/2] != -1 && nivel[ a[u][n/2] ] >= nivel[v])
			u = a[u][n/2];
		n = n/2 - 1;
	}
	*/
	
	for(int i = MAXL - 1; i >= 0; i--)
		if(nivel[u] - (1 << i) >= nivel[v])
			u = a[u][i];
	
	if(u == v)
		return u;

	for(int i = MAXL - 1; i >= 0; i--) {
		if(a[u][i] != -1 && (a[u][i] != a[v][i])) {
			u = a[u][i];
			v = a[v][i];
		}
	}

	return pai[u];
}

int main() {
	int N, Q, u, v;
	ll p;
	while(scanf("%d", &N), N) {
		for(int i = 1; i <= N - 1; i++) {
			scanf("%d %lld", &u, &p);
			G[i].push_back(edge(u, p));
			G[u].push_back(edge(i, p));
		}
		bfs(0);

		memset(a, -1, sizeof a);		    
		for(int i = 1; i < N; i++) 
			a[i][0] = pai[i];
		for(int j = 1;j < MAXL;j++)
			for(int i = 1; i < N; i++)
				a[i][j] = a[ a[i][j-1] ][j-1];
		
		scanf("%d", &Q);
		scanf("%d %d", &u, &v);

		printf("%lld", d[u] + d[v] - 2 * d[lca(u, v)]);
		
		for(int i = 1; i < Q; i++) {
			scanf("%d %d", &u, &v);
			printf(" %lld", d[u] + d[v] - 2 * d[lca(u, v)]);
		}
		printf("\n");
		
		for(int i = 0; i < N; i++)
			G[i].clear();
	}
	return 0;
}
