#include <bits/stdc++.h>
#define C 40000
#define V 400000
#define INF 0x3f3f3f3f

using namespace std;

struct edge {
	int v, p;
	
	edge() {}
	
	edge(int a, int b) {
		v = a;
		p = b;
	}
};

vector<edge> G[C];

int d[C][2];

struct compare {
	bool operator()(pair<int, int> u, pair<int, int> v) {
		return d[u.first][u.second] > d[v.first][v.second];
	}
};

void dijkstra(int s, int n) {
	priority_queue<pair<int, int>, vector< pair<int, int> >, compare> A;
    memset(d, INF, sizeof d);
    d[s][1] = 0;

    for(register int u = 0; u < n; u++) {
        A.push(make_pair(u, 0));
        A.push(make_pair(u, 1));
    }

    int u, caminhoPar, novoCaminho;
    edge v;
    while(A.size() >= 1) {
        u = A.top().first;
        caminhoPar = A.top().second;
        A.pop();
        for(register int i = 0; i < G[u].size(); i++) {
            v = G[u][i];
            novoCaminho = caminhoPar ? 0 : 1;
            if(d[v.v][novoCaminho] > d[u][caminhoPar] + v.p) {
                d[v.v][novoCaminho] = d[u][caminhoPar] + v.p;
                A.push(make_pair(v.v, novoCaminho));
            }
        }
    }
}

int main() {
    int c, v, g, u, w;
        
    scanf("%d %d", &c, &v);
    for(register int i = 0; i < v; i++) {
        scanf("%d %d %d", &u, &w, &g);
        u--; w--;

        G[u].push_back(edge(w, g));
        G[w].push_back(edge(u, g));
    }

    dijkstra(0, c);

	d[c - 1][1] == INF ? printf("-1\n") : printf("%d\n", d[c - 1][1]);

    
    for(register int u = 0; u < c; u++) {
        G[u].clear();
    }
 
    return 0;
}
