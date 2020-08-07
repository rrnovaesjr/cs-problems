#include <bits/stdc++.h>
#define MAXN 100050
#define LOGN 26

using namespace std;

vector<int> G[MAXN];

int a[MAXN][LOGN];

int vis[MAXN];

int d[MAXN];

void dfs(int u) {
	vis[u] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(!vis[v]) {
			d[v] = d[u] + 1;
			a[v][0] = u;
			dfs(v);
		}	
	}
}

int lca(int u, int v) {
	if(d[u] < d[v])
		swap(u, v);
	
	int n = 0;
	while(a[u][n] != -1)
		n++;
	
	for(int i = n; i >= 0; i--)
		if(d[u] - (1 << i) <= d[v])
			u = a[u][i];
	
	if(u == v)
		return u;
	
	for(int i = n; i >= 0; i--) {
		if(a[u][i] != a[v][i]) {
			u = a[u][i];
			v = a[v][i];
		}
	}
	return a[u][0];
}

int main() {
	int N, Q, w, u, v;
	
	while(cin >> N) {
		memset(a, -1, sizeof a);
		memset(d, 0, sizeof d);
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= N; i++)
			G[i].clear();
	
		for(u = 1; u <= N; u++) {
			cin >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(u = 1; u <= N; u++)
			if(!vis[u])
				dfs(u);
		for(int j = 1; j < LOGN; j++)
			for(u = 1; u <= N; u++)
				if(a[u][j - 1] != -1)
					a[u][j] = a[ a[u][j - 1] ][ j - 1 ];
		
		cin >> Q;
		while(Q--) {
			cin >> u >> v;
			w = lca(u, v);
			if(w == -1)
				cout << w << endl;
			else
				cout << d[u] + d[v] - 2 * d[w] << endl;
		}
	}

	return 0;
}
