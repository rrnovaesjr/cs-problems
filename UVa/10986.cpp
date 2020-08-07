#include <bits/stdc++.h>
#define MAXN 20200
#define INF 0x3f3f3f3f

using namespace std;

struct Edge {

	int v, w;
	
	Edge() {}
	
	Edge(int v, int w): v(v), w(w) {}
};

int N, n, m, S, T;

int dist[MAXN];

vector<Edge> G[MAXN];

struct comp {
	bool operator() (int u, int v) { return dist[u] > dist[v]; }
};

void dijkstra() {
	memset(dist, INF, sizeof(int) * n);
	dist[S] = 0;
	priority_queue<int, vector<int>, comp> q;
	q.push(S);
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		for(int i = 0; i < G[u].size(); i++) {
			Edge v = G[u][i];
			if(dist[v.v] > dist[u] + v.w) {
				dist[v.v] = dist[u] + v.w;
				q.push(v.v);
			}
		}
	}
}

int main() {
	int u, v, w;
	scanf("%d", &N);
	for(int t = 1; t <= N; t++) {
		scanf("%d %d %d %d", &n, &m, &S, &T);
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(Edge(v, w));
			G[v].push_back(Edge(u, w));
		}
		dijkstra();
		if(dist[T] == INF) printf("Case #%d: unreachable\n", t);
		else printf("Case #%d: %d\n", t, dist[T]);
		for(int i = 0; i < n; i++) G[i].clear();
	}
	return 0;
}
