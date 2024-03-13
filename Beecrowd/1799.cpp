#include <bits/stdc++.h>
#define N 5500
#define ENTRADA "Entrada"
#define QUEIJO "*"
#define SAIDA "Saida"

using namespace std;

map<string, int> mapa;

vector<int> G[N];

int visitado[N];

int d[N];

void bfs(int s) {
  memset(visitado, 0, sizeof visitado);
  d[s] = 0;
  visitado[s] = 1;
  
  queue<int> Q;
  Q.push(s);
  int u, v;
  while(!Q.empty()) {
    u = Q.front();
    Q.pop();
    for(int i = 0; i < G[u].size(); i++) {
      v = G[u][i];
      if(!visitado[v]) {
	visitado[v] = 1;
	d[v] = d[u] + 1;
	Q.push(v);
      }
    }
  }
}

int main() {
    int n, m, u, v;
    string a, b;
    
    cin >> n >> m;
    int cont = 0;
    for(int i = 0; i < m; i++) {
	cin >> a >> b;
	if(mapa.count(a) == 0)
	    mapa[a] = cont++;
	if(mapa.count(b) == 0)
	    mapa[b] = cont++;
	G[mapa[a]].push_back(mapa[b]);
	G[mapa[b]].push_back(mapa[a]);
    }
    bfs(mapa[ENTRADA]);
    int dEntradaQueijo = d[mapa[QUEIJO]];
     bfs(mapa[QUEIJO]); 
    int dQueijoSaida = d[mapa[SAIDA]];    
    cout << dEntradaQueijo + dQueijoSaida << endl;
    return 0;
}