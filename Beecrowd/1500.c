#include <stdio.h>
#include <string.h>
#define MAXN 101100
#define RAIZ 0

typedef long long ll;

ll arvore[4 * MAXN];

ll v[MAXN];

ll lz[4 * MAXN];

ll constroi(int no, int esq, int dir) {
	if(esq == dir) {
		arvore[no] = v[esq];
		return arvore[no];
	}
	int meio = (esq + dir)/2;
	ll p1 = constroi((no * 2) + 1, esq, meio);
	ll p2 = constroi((no * 2) + 2, meio + 1, dir);
	arvore[no] = p1 + p2;
	return arvore[no];
}

void propaga(int no, int l, int r, int meio) {
	arvore[(no * 2) + 1] += lz[no] * (meio - l + 1);
	arvore[(no * 2) + 2] += lz[no] * (r - (meio + 1) + 1);
	lz[(no * 2) + 1] += lz[no];
	lz[(no * 2) + 2] += lz[no];
	lz[no] = 0;
}

ll consulta(int no, int l, int r, int esq, int dir) {
	if(l > dir || r < esq)
		return 0;

	else if(l >= esq && r <= dir)
		return arvore[no];

	int meio = (l + r)/2;
	propaga(no, l, r, meio);
	ll p1 = consulta((no * 2) + 1, l, meio, esq, dir);
	ll p2 = consulta((no * 2) + 2, meio + 1, r, esq, dir);
	return p1 + p2;
}

ll atualiza(int no, int l, int r, int esq, int dir, ll k) {
	if(l > dir || r < esq) {
		return arvore[no];
	}

	else if(l >= esq && r <= dir) {
		arvore[no] += k * (r - l + 1);
		lz[no] += k;
		return arvore[no];
	}

	int meio = (l + r)/2;
	propaga(no, l, r, meio);

	ll p1 = atualiza((no * 2) + 1, l, meio, esq, dir, k);
	ll p2 = atualiza((no * 2) + 2, meio + 1, r, esq, dir, k);

	arvore[no] = (p1 + p2);
	return arvore[no];
}

int main() {
	int N, C, T, op, p, q, i;
	
	ll k;
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d", &N, &C);
		memset(v, 0, sizeof(int) * N);
		memset(lz, 0, sizeof lz);
		memset(arvore, 0, sizeof arvore);
		
		constroi(RAIZ, 0, N - 1);		
		for(i = 0; i < C; i++) {
			scanf("%d %d %d", &op, &p, &q);
			p--, q--;
			
			switch(op) {
				case 0:
					scanf("%lld", &k);					
					atualiza(RAIZ, 0, N - 1, p, q, k);	
					break;
				default:
					printf("%lld\n", consulta(RAIZ, 0, N - 1, p, q));
			}
		}
	}
	return 0;
}
