#include <bits/stdc++.h>
#define MAXN 55000

using namespace std;

vector<int> G[MAXN];

int s[MAXN];

int vis[MAXN];

int dfs(int u) {

	vis[u] = 1;;
	int v;
	int dist = 0;
	for(int i = 0; i < G[u].size(); i++) {
		v = G[u][i];
	
		if(!vis[v])
			dist += dfs(v) + 1;
	}
	vis[u] = 0;
	return (s[u] = dist);
}

int main() {
	int T, n, u, v, theGuy;
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {	
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &u, &v);
			u--, v--;
			G[u].push_back(v);
		}

		memset(s, -1, sizeof s);
		memset(vis, 0, sizeof vis);
		for(int w = 0; w < n; w++)
			if(s[w] == -1)
				dfs(w);

		theGuy = 0;
		for(int w = 1; w < n; w++)
			if(s[w] > s[theGuy])
				theGuy = w;
		printf("Case %d: %d\n", c, theGuy + 1);

		for(int i = 0; i < n; i++)
			G[i].clear();
	}

}
