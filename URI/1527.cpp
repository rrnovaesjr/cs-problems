#include <bits/stdc++.h>
#define maxn 800500

using namespace std;

typedef long long ll;

int rep[maxn];

ll pontos[maxn];

void make_set(int n) {
  rep[n] = n;
}

int find(int n) {
  if(rep[n] == n)
    return n;
  return rep[n] = find(rep[n]);
}

void union_set(int s, int t) {
  if(pontos[find(s)] > pontos[find(t)]) {
    pontos[find(s)] += pontos[find(t)];
    rep[find(t)] = find(s);
  }
  else if(pontos[find(s)] <= pontos[find(t)]) {
    pontos[find(t)] += pontos[find(s)];
    rep[find(s)] = find(t);
  }
}


int main() {
  int N, M, op, u, v, bat;
  
  while(scanf("%d %d", &N, &M), (N || M)) {
    bat = 0;
    for(int i = 0; i < N; i++) {
	make_set(i);
	scanf("%lld", &pontos[i]);
    }

    for(int i = 0; i < M; i++) {
	scanf("%d", &op);
	switch(op) {
	  case 1:
	     scanf("%d %d", &u, &v);
	     u--, v--;
	     union_set(u,v);
	     break;
	  default:
	     scanf("%d %d", &u, &v);
	     u--, v--;
	     if(find(u) == find(0)) {
		if(pontos[find(u)] > pontos[find(v)])
		  bat++;
	     }
	     else if(find(v) == find(0)) {
		if(pontos[find(v)] > pontos[find(u)])
		  bat++;
	     }

	}
    }
    printf("%d\n", bat);
  }
  return 0;
}