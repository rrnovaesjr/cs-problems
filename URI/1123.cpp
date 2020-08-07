#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 290

using namespace std;

int G[N][N];

int d[N][N];

int dist[N];

bool compare(int u, int v) {
	return d[u] < d[v];
}


void dijkstra(int s, int n) {
	memset(dist, INF, sizeof dist);
	dist[s] = 0;
	vector<int> heap;

	for(int u = 0; u < n; u++)
		heap.push_back(u);

	make_heap(heap.begin(), heap.end(), compare);
	while(!heap.empty()) {
		int u = heap.front();
		pop_heap(heap.begin(), heap.end(), compare);
		heap.pop_back();
		for(int v = 0; v < n; v++) {
			if(dist[v] > dist[u] + G[u][v]) {
				dist[v] = dist[u] + G[u][v];
				heap.push_back(v);
				push_heap(heap.begin(), heap.end(), compare);
			}
		}

	}
}


int main() {
	int n, m, c, k;
	int u, v, p;
	while(scanf("%d %d %d %d", &n, &m, &c, &k) == 4, n || m || c || k) {
		memset(G, INF, sizeof G);
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &p);
			if(u >= c && v >= c){ 	
				G[u][v]=p;
				G[v][u]=p;
			}
			if(u>=c && v<c) 
				G[u][v] = p;
			if(u<c && v>=c) 
				G[v][u] = p;	
			if(u < c && v < c && abs(u - v) == 1) {
				G[u][v] = p;
				G[v][u] = p;
			}
		}

		dijkstra(k, n);
		printf("%d\n", dist[c - 1]);
	}

	return 0;
}
