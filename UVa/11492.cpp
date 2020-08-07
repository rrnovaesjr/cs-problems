#include <bits/stdc++.h>
#define MAXM 10000
#define INF 0x3f3f3f3f

using namespace std;

struct edge {
	int v;
	string p;
	
	edge() {}
	
	edge(int a, string b) {
		v = a;
		p = b;
	}
};

vector<edge> g[MAXM];

int d[MAXM][256];

struct compare {
	bool operator()(const pair<int, char> &a, const pair<int, char> &b) const {
		return d[a.first][a.second] > d[b.first][b.second];
	}
};

void dj(int s, int m) {
	priority_queue< pair<int, char>, vector< pair<int, char> >, compare> heap;
	
	memset(d, INF, sizeof d);
	d[s]['a' - 1] = 0;
	for(int i = 0; i < m; i++)
		for(char j = 'a' - 1; j <= 'z'; j++)
			heap.push( make_pair(i, j) );
	
	int u, peso;
	char inicial, novaAresta;
	edge v;
	while(!heap.empty()) {
		u = heap.top().first;
		inicial = heap.top().second;
		heap.pop();
		for(int i = 0; i < g[u].size(); i++) {
			v = g[u][i];
			peso = v.p.size();
			novaAresta = v.p[0];
			
			if(novaAresta == inicial)
				continue;
				
			if(d[v.v][novaAresta] > d[u][inicial] + peso) {
				d[v.v][novaAresta] = d[u][inicial] + peso;
				heap.push( make_pair(v.v, novaAresta) );
			}
		}
	}
}

int main() {
	map<string, int> p;	
	map<int, string> pr;
	int m, cont, minTam;
	string s, f;
	string i, j, k;
	while(scanf("%d", &m), m) {
		
		cin >> s >> f;
		cont = 0;
		
		p[s] = cont++;
		p[f] = cont++;
		
		for(int a = 0; a < m; a++) {
			cin >> i >> j >> k;
			
			if(p.count(i) == 0)
				p[i] = cont++;
			
			if(p.count(j) == 0)
				p[j] = cont++;

			g[ p[i] ].push_back( edge(p[j], k) );
			g[ p[j] ].push_back( edge(p[i], k) );			
		}
				
		minTam = INF;
		dj(p[s], cont);
		
		for(int j = 'a' - 1; j <= 'z'; j++)
			minTam = min(minTam, d[p[f]][j]);
	
		if(minTam == INF)
			printf("impossivel\n");
		else
			printf("%d\n", minTam);
	
		p.clear();
				
		for(int i = 0; i < cont; i++)
			g[i].clear();
	}

	return 0;
}
