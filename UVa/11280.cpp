#include <bits/stdc++.h>
#define MAXN 101
#define INF 0x3f3f3f3f
#define S "Calgary"
#define D "Fredericton"

using namespace std;

int G[MAXN][MAXN];

int dist[MAXN][MAXN][MAXN];

void bellman(int n) {
	for(int k = 0; k < n; k++) {
		for(int u = 0; u < n; u++) {
			for(int v = 0; v < n; v++) {
				dist[u][v][k] = INF;
				
				if(u == v)
					dist[u][v][k] = 0;
				if(k == 0 && G[u][v] != -1)
					dist[u][v][k] = G[u][v];
			}
		}
	}

	for(int k = 1; k < n; k++) {
		for(int u = 0; u < n; u++) {
			for(int v = 0; v < n; v++) {
				if(dist[u][v][k] > dist[u][v][k - 1])
					dist[u][v][k] = dist[u][v][k - 1];
				for(int x = 0; x < n; x++)
					if(G[u][x] != -1)
						dist[u][v][k] = min(dist[u][v][k], G[u][x] + dist[x][v][k - 1]);
			}
		}
	}

}

int main() {
	int c, n, m, p, q, k;
	string sep = "", su, sv;
	map<string, int> mp;
	
	cin >> c;
	for(int a = 1; a <= c; a++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> su;
			mp[su] = i;
		}
		cin >> m;
		memset(G, -1, sizeof G);
		for(int i = 0; i < m; i++) {
			cin >> su >> sv >> p;
			if(G[mp[su]][mp[sv]] == -1)
				G[mp[su]][mp[sv]] = p;
			else
				if(p < G[mp[su]][mp[sv]])
					G[mp[su]][mp[sv]] = p;

		}
		cin >> q;
		cout << sep << "Scenario #" << a << endl;
		sep = "\n";
		bellman(n);
		for(int i = 0; i < q; i++) {
			cin >> k;
			if(k >= n)
				k = n - 1;
			if(dist[mp[S]][mp[D]][k] < INF)
				cout << "Total cost of flight(s) is $" << dist[mp[S]][mp[D]][k] << endl;
			else
				cout << "No satisfactory flights" << endl;
		}
		mp.clear();
	}
	return 0;
}
