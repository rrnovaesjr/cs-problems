#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 800

vector<int> G[MAXN];
int N, M, B, D;

typedef unsigned long long ull;

ull W[MAXN][MAXN], R[MAXN][MAXN];

int pai[MAXN], vis[MAXN];


ull bfs(int s, int t){ 
    int u, v;
    queue<int> Q;
    memset(pai, 0, sizeof pai);
    memset(vis, 0, sizeof vis);
    
    pai[s] = s;
    vis[s] = 1;
    
    Q.push(s);
    
    bool flag = false;
    
    while(!Q.empty() && !flag) {
        u = Q.front(); Q.pop();
        
        for(int i = 0; i < G[u].size() && !flag; ++i) {
            v = G[u][i];
            
            if ( W[u][v] - R[u][v] > 0 && !vis[v]) {
                pai[v] = u;
                vis[v] = 1;
                if(v == t)
                    flag = true;
                
                Q.push(v);
            }
        }   
    }
    
    ull res = INF;
            
    if(flag) {
        
        v = t;
        while (v != s) {
            u = pai[v];
            res = min(res, W[u][v] - R[u][v]);
            v = u;
        }
    } 
    
    return res;
}

int edmondKarp(int s, int t) {
    
    ull f = 0;
    int u, v;
    
    while (true) {
        ull w = bfs(s,t);
        if(w == INF)
            break;
            
        f += w;
        
        v = t;
        while (v != s) {
            u = pai[v];
            R[u][v] += w;
            R[v][u] -= w;
            v = u;
        }
    }
    
    return f;
}

#define out(x) (x+N)

int main() {
    int u, v;
    ull w;
    
    while(cin >> N){
        int s, t;
        
        memset(W, 0, sizeof W);
        memset(R, 0, sizeof R);
        
        s = 0;
        t = 2*N + 2;
        
        for(int i = 1; i <= N; ++i) {
            cin >> w;
            
            W[i][out(i)] = w;
            G[i].push_back(out(i));
            G[out(i)].push_back(i);
        }
        
        cin >> M;
        
        for(int i = 0; i < M; ++i) {
            
            cin >> u >> v >> w;
            
            G[out(u)].push_back(v);
            G[v].push_back(out(u));
            W[out(u)][v] = w;
        }
        
        cin >> B >> D;
        
        for(int i = 0; i < B; ++i) {
            cin >> u;
            
            G[s].push_back(u);
            G[u].push_back(s);
            
            W[s][u] = INF;
        }
        
        for (int i = 0; i < D; ++i) {
            cin >> u;
            
            G[out(u)].push_back(t);
            G[t].push_back(out(u));
            
            W[out(u)][t] = INF;
        }
        
        cout << edmondKarp(s, t) << endl;
        
        for(int i = 0; i <= t; ++i)
            G[i].clear();
    }
    
    return 0;
}
