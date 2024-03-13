#include <bits/stdc++.h>
#define MAXN 102
#define LET 10
#define INF 0x3f3f3f3f
#define MAXM 2

using namespace std;

char A[LET + 1][MAXM];

char v[(1 << LET) + 1];

char G[MAXN][MAXN];

int d[MAXN][MAXN];

int N;

int dist;

int p(char a) {
	if(toupper(a) == a)
		return a - 'A';
	return a - 'a' + 10;
}

typedef pair<int, int> pii;

vector<pii> obtemP(pii coord) {
    int i = coord.first, j = coord.second;
    char cam = G[i][j];
    char vizinho;
      
    int flagI = 0, flagJ = 0;
  
    if(j == 0)
        flagJ = -1;
    else if(j == N - 1)
        flagJ = 1;
      
    if(i == 0)
        flagI = -1;
    else if(i == N - 1)
        flagI = 1;  
  
    vector<pii> r;
      
    if(flagJ != -1) {
        vizinho = G[i][j - 1];
        r.push_back( make_pair( i, j - 1) );
    }
      
    if(flagJ != 1) {
        vizinho = G[i][j + 1];
        r.push_back( make_pair( i, j + 1) );
    }
      
    if(flagI != -1) {
        vizinho = G[i - 1][j];
        r.push_back( make_pair( i - 1, j) );
    }
  
    if(flagI != 1) {
        vizinho = G[i + 1][j];
        r.push_back( make_pair( i + 1, j) );
    }
      
    return r;
}

int bfs(int mask) {
	pii s = make_pair(0, 0);
	pii f = make_pair(N - 1, N - 1);
	char letra;
	memset(d, 0, sizeof d);
	d[s.first][s.second] = 1;
	queue<pii> Q;
	letra = G[s.first][s.second];
	if(mask & (1 << p(letra)))		
		Q.push(s);
	
	pii u, v;
	vector<pii> ladj;
	while(Q.size() >= 1) {
		u = Q.front();
		Q.pop();
		if(u == f)
			return d[u.first][u.second];
		ladj = obtemP(u);
		for(int i = 0; i < ladj.size(); i++) {
			v = ladj[i];
			
			if(d[v.first][v.second] > 0)
				continue;
			
			letra = G[v.first][v.second];
			if(!(mask & (1 << p(letra))))
				continue;
			
			d[v.first][v.second] = d[u.first][u.second] + 1;
			Q.push(v);
		}
	}
	return INF;
}

void bt(int i, int mask) {
	if(i == LET) {
		dist = min(dist, bfs(mask));
		return;
	}
	for(int j = 0; j < MAXM; j++) {
		v[i] = A[i][j];
		bt(i + 1, mask ^ (1 << p(A[i][j])));
	}
}

int main(void) {
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> G[i][j];

	for(int i = 0; i < LET; i++) {
		A[i][0] = 'a' + i;
		A[i][1] = 'A' + i;
	}

	dist = INF;
	bt(0, 0);

	if(dist == INF)
		printf("-1\n");
	else
		printf("%d\n", dist);
	return 0;
}

