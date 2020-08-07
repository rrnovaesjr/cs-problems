#include <bits/stdc++.h>
#define MAXN 1101010
#define RAIZ 0

using namespace std;

typedef map<int, int> mii;

int f[MAXN];

int c[MAXN];

int v[MAXN];

int arvore[MAXN * 4];

int n;

int fgs[2 * MAXN];

int l(int v) {
	return v >= 0 ? v : 2 * (-v);
}

int constroi(int no, int esq, int dir) {
	/*
	* É um nó folha
	*/	
	if(esq == dir) {
		arvore[no] = f[esq];
		return arvore[no];
	}
	/*
	* Não é um nó folha
	*/
	int meio = (esq + dir)/2;
	int fesq = constroi((no * 2) + 1, esq, meio);
	int fdir = constroi((no * 2) + 2, meio + 1, dir);

	arvore[no] = max(fesq, fdir);

	return arvore[no];
}


int consulta(int no, int l, int r, int esq, int dir) {
	if(l > dir || r < esq)
		return 0;
		
	else if(l >= esq && r <= dir)
		return arvore[no];

	int meio = (l + r)/2;
	int fesq = (no * 2) + 1;
	int fdir = (no * 2) + 2;

	int p = consulta(fesq, l, meio, esq, dir);
	int q = consulta(fdir, meio + 1, r, esq, dir);
	
	return max(p, q);
}

int main() {
	
	int q, r, s, i;
	while(scanf("%d", &n), n) {
		scanf("%d", &q);
		
		memset(fgs, 0, sizeof fgs);
		memset(c, -1, sizeof c);
		
		scanf("%d", &v[0]);
		fgs[l(v[0])]++;
		c[0] = 0;
		for(i = 1; i < n; i++) {
			scanf("%d", &v[i]);
			fgs[l(v[i])]++;
		}
		
		for(i = 0; i < n; i++) {
			f[i] = fgs[l(v[i])];
			if(c[f[i]] == -1)
				c[f[i]] = i;
		}

		constroi(RAIZ, 0, n - 1);

		for(i = 0; i < q; i++) {
			scanf("%d %d", &r, &s);
			r--, s--;
			printf("%d\n", consulta(RAIZ, 0, n - 1, r, s));
		}
	}

	return 0;
}
