#include <bits/stdc++.h>
#define N 10000
#define INF 0x3f3f3f

using namespace std;

class Grafo {
	public:
		int v;
		int p;
};

vector<Grafo> ladj[N];

int dist[N];

bool bellman(int n, int s) {
	
	int v, p;

	memset(dist, INF, sizeof dist);
	dist[s] = 0;	
	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < ladj[u].size(); j++) {
				v = ladj[u][j].v;
				p = ladj[u][j].p;
				if(dist[v] > dist[u] + p)
					dist[v] = dist[u] + p;
			}
		}
	}
	
	for(int u = 0; u < n; u++) {
		for(int j = 0; j < ladj[u].size(); j++) {
			v = ladj[u][j].v;
			p = ladj[u][j].p;
			if(dist[v] > dist[u] + p)
				return true;
		}
	}
	
	return false;
}

int main() {
	int c, n, m, u;
	Grafo g;
	cin >> c;
	while(c--) {
		cin >> n >> m;
		
		for(int i = 0; i < m; i++) {
			cin >> u >> g.v >> g.p;
			ladj[u].push_back(g);
		}
		
		if(bellman(n, 0))
			cout << "possible" << endl;
		else
			cout << "not possible" << endl;
			
		for(int u = 0; u < n; u++)
			ladj[u].clear();
	
	}
	return 0;
}
