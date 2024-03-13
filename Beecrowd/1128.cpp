#include <bits/stdc++.h>
#define N 2020

using namespace std;

vector<int> G[N];

vector<int> Gt[N];

int vis[N];

void dfs(int u) {
	vis[u] = 1;
	for(int i = 0; i < (int) G[u].size(); i++) {
		int v = G[u][i];
		if(!vis[v]) {
			dfs(v);
		}
	}
}

void dfst(int u) {
	vis[u] = 1;
	for(int i = 0; i < (int) Gt[u].size(); i++) {
		int v = Gt[u][i];
		if(!vis[v]) {
			dfst(v);
		}
	}
}



int main() {
	int n, m, u, v, c, iscon;
	while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
		while(m--) {
			scanf("%d %d %d", &u, &v, &c);
			G[u].push_back(v);
			Gt[v].push_back(u);
			if(c == 2) {
				G[v].push_back(u);
				Gt[u].push_back(v);
			}		
		}
		memset(vis, 0, sizeof(vis));
		iscon = 1;
		dfs(1);
		for(int i = 1; i <= n && iscon; i++)
			if(!vis[i])
				iscon = 0;
		if(iscon) {
			memset(vis, 0, sizeof(vis));
			dfst(1);
			for(int i = 1; i <= n && iscon; i++)
				if(!vis[i])
					iscon = 0;
		}
		printf("%d\n", iscon);
		for(int i = 0; i <= n; i++) {
			G[i].clear();
			Gt[i].clear();
		}
	}

	return 0;
}
