#include <bits/stdc++.h>
#define MAXS 11050
#define INF 0x3f3f3f3f

using namespace std;

struct aresta {
    int v, p;
    
    aresta() {}
    
    aresta(int a, int b) {
        v = a;
        p = b;
    }
};

vector<aresta> G[MAXS];

vector<aresta> G_[2 * MAXS];

int d[2 * MAXS];

int p[MAXS];

int vis[MAXS];

int S, T, Q, comp, u, v, s;

void dfsDeOrigem(int u) {
    vis[u] = 1;    
    aresta v;
    for(int i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        /*
        * Não posso visitar o túnel de onde eu
        * vim imediatamente
        */
        if(p[u] == v.v) {
            continue;
        }
        /*
        * Se o salão pelo que passei já foi visitado,
        * e a distância do salão onde eu estou para ele
        * é maior ou igual ao comprimento da dona minhoca,
        * então eu posso percorrer este ciclo.
        */
        if(vis[v.v] && (d[u] + v.p) - d[v.v] >= comp)
			G_[v.v].push_back(aresta(S + v.v, (d[u] + v.p) - d[v.v]));
        	
        if(!vis[v.v]) {
            p[v.v] = u;
            d[v.v] = d[u] + v.p;
            dfsDeOrigem(v.v);
        }
    }
}

struct Compare {
	bool operator() (int a, int b) {
		return d[a] > d[b];
	}
};

int djk() {
	priority_queue<int, vector<int>, Compare> Q;
	
	memset(d, INF, sizeof d);
	
	d[s] = 0;
	Q.push(s);
	
	int u;
	aresta v;
	while(Q.size() >= 1) {
		u = Q.top();
		Q.pop();
		
		for(int i = 0; i < G_[u].size(); i++) {
			v = G_[u][i];
			if(d[v.v] > d[u] + v.p) {
				d[v.v] = d[u] + v.p;
				Q.push(v.v);
			}
		}
	}
	return -1;
}

int main() {
    while(scanf("%d %d", &S, &T) == 2) {
        for(int i = 0; i < T; i++) {
            scanf("%d %d %d", &u, &v, &comp);
            u--, v--;
            G[u].push_back(aresta(v, comp));
            G[v].push_back(aresta(u, comp));
        }

        scanf("%d", &Q);
        while(Q--) {            
            scanf("%d %d", &s, &comp);
			s--;

			for(int i = 0; i < S; i++) {
				G_[i].clear();
				G_[S + i].clear();
		        for(int j = 0; j < G[i].size(); j++) {
		        	G_[i].push_back(aresta(G[i][j].v, G[i][j].p));
		        	G_[S + i].push_back(aresta(G[i][j].v + S, G[i][j].p));
				}
			}

			d[s] = 0;
			p[s] = -1;
            memset(vis, 0, sizeof vis);
			dfsDeOrigem(s);
            
            djk();
            
            if(d[S + s] == INF)
            	printf("-1\n");
            else   
 				printf("%d\n", d[S + s]);
        }
        
        for(int i = 0; i < S; i++) {
            G[i].clear();
            G_[i].clear();
        }
    }
    

    return 0;
}
