#include <bits/stdc++.h>
#define MAXN 1000020

using namespace std;

typedef long long ll;

int rep[MAXN];

void make_set(int n) {
	rep[n] = n;
}

int find(int n) {
	if(rep[n] == n)
		return n;
	return rep[n] = find(rep[n]);
}

void union_set(int u, int v) {
	rep[find(u)] = find(v);
}

struct edge {
	int u, v, p;

	edge() {}
	
	edge(int a, int b, int c) {
		u = a;
		v = b;
		p = c;
	}
	
	bool operator < (const edge &e) {
		return p < e.p;
	}
};

vector<edge> arestas;

ll kruskal(int n) {
	sort(arestas.begin(), arestas.end());
	int u, v;
	ll pesoTotal = 0LL;
	
	for(int u = 1; u <= n; u++)
		make_set(u);
				
	for(int i = 0; i < arestas.size(); i++) {
		v = arestas[i].v;
		if(find(arestas[i].u) != find(arestas[i].v)) {
			pesoTotal += arestas[i].p;
			union_set(arestas[i].u, arestas[i].v);
		}
	}
	
	return pesoTotal;
}

int main() {
	int N, M, K, u, v, p, total;
	string sep = "";
	while(scanf("%d", &N) == 1) {
		cout << sep;
		sep = "\n";
		total = 0;
		for(int i = 1; i <= N - 1; i++) {
			scanf("%d %d %d", &u, &v, &p);
			total += p;
		}
		
		scanf("%d", &K);
		for(int i = 0; i < K; i++) {
			scanf("%d %d %d", &u, &v, &p);
			arestas.push_back( edge(u, v, p) );
		}
		
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &p);
			arestas.push_back( edge(u, v, p) );
		}
		
		printf("%d\n%lld\n", total, kruskal(N));
		
		arestas.clear();
	}


	return 0;
}
