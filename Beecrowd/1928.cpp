#include <bits/stdc++.h>
#define MAXN 55000
#define LOGN 18

using namespace std;

vector<int> G[MAXN];

int vis[MAXN];
int d[MAXN];
int cartas[MAXN];
int par[MAXN];

int a[MAXN][LOGN];

void dfs(int u) {
	vis[u] = 1;
	int v;
	for(register int i = 0; i < G[u].size(); i++) {
		v = G[u][i];
		if(!vis[v]) {
			a[v][0] = u;
			d[v] = d[u] + 1;
			dfs(v);
		}
	}

}

int lca(int u, int v) {
	if(d[u] < d[v])
		swap(u, v);

	// Outras formas ruins:
	//for(int i = 1; d[u] != d[v]; i++) {
	//	if(d[ a[u][i] ] < d[v] || a[u][i] != -1) {
	//		u = a[u][i - 1];
	//		i--;
	//	}
	//}


	//int n = LOGN - 1;
	//while(d[u] != d[v]) {
	//	if(a[u][n/2] != -1 && d[ a[u][n/2] ] >= d[v])
	//		u = a[u][n/2];
	//	n = n/2 - 1;
	//}

	register int n = 0;
	while(a[u][n] != -1)
		n++;

	for(register int i = n; i >= 0; i--)
		if(d[u] - (1 << i) >= d[v])
			u = a[u][i];


	if(u == v || a[u][0] == v)
		return v;

	for(register int i = n; i >= 0; i--) {
		if(a[u][i] != a[v][i]) {
			u = a[u][i];
			v = a[v][i];
		}
	}
	
	return a[u][0];
}

int main() {
	int n, u, v;

	scanf("%d", &n);
	memset(cartas, 0, sizeof(int) * (n + 1));
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &u);
		if(cartas[u])
			par[cartas[u]] = i;
		else
			cartas[u] = i;
	}

	for(int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	d[1] = 0;
	
	memset(a, -1, sizeof a);
	
	dfs(1);

	for(register int j = 1; j < LOGN; j++)
		for(register int i = 1; i <= n; i++)
			if(a[i][j - 1] != -1)
				a[i][j] = a[ a[i][j - 1] ][j - 1];

	int maxp = 0;
	for(register int c = 1; c <= n; c++)
		if(par[c])
			maxp += d[c] + d[ par[c] ] - 2 * d[ lca(c, par[c]) ];

	printf("%d\n", maxp);
	
	return 0;
}
