#include <bits/stdc++.h>

#define N 10500

 

using namespace std;

 

struct Edge {

    int v;

   

    int p;

   

    Edge() {}

   

    Edge(int v, int p) { this->v = v; this->p = p; }

};

 

vector<Edge> G[N];

 

int cofre[N];

 

int vis[N];

 

int pai[N];

 

int n, C, a, b, c, total;

 

void dfs(int u, int pesoPaiParaU) {

    vis[u] = 1;

    for(int i = 0; i < G[u].size(); i++) {

        Edge v = G[u][i];

        if(!vis[v.v]) {

            pai[v.v] = u;

            dfs(v.v, v.p);

        }

    }

    int cofreU = cofre[u];

    cofre[u] = 0;

    if(pai[u] != -1) {

        int a = pai[u];

        cofre[a] += cofreU;

    }

    total += (2 * (int) ceil(cofreU /(double) C)) * pesoPaiParaU;

}

 

int main() {

    while(scanf("%d %d", &n, &C) == 2) {

        memset(cofre, 0, sizeof cofre);

        memset(vis, 0, sizeof vis);

        memset(pai, -1, sizeof pai);

        total = 0;

       for(int i = 0; i < n; i++)

            scanf("%d", &cofre[i]);

        for(int i = 0; i < n - 1; i++) {

            scanf("%d %d %d", &a, &b, &c);

            a--; b--;

            G[a].push_back(Edge(b, c));

            G[b].push_back(Edge(a, c));

        }

        dfs(0, 0);

        printf("%d\n", total);

        for(int i = 0; i < n; i++)

            G[i].clear();

    }

    return 0;

}
