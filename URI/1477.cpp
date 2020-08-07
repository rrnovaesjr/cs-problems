#include <bits/stdc++.h>
#define N 200000
#define N_JOGADAS 3
#define RAIZ 0

struct Tree {
	
	int homem;
	
	int elefante;
	
	int rato;
	
	Tree(bool construcao = false) {
		if(construcao) {
			homem = 1;
		} else {
			homem = 0;
		}
		elefante = 0;
		rato = 0;
	}

	Tree& operator + (const Tree &a) {
		Tree *nova = new Tree();
		nova->homem = a.homem + this->homem;
		nova->elefante = a.elefante + this->elefante;
		nova->rato = a.rato + this->rato;
		return *nova;		
	}
	
};

Tree arvore[4 * N];

int lz[4 * N];

Tree constroi(int no, int esq, int dir) {
	lz[no] = 0;
	if(esq == dir) {
		arvore[no] = Tree(true);
		return arvore[no];
	}
	int meio = (esq + dir)/2;
	Tree p1 = constroi((no * 2) + 1, esq, meio);
	Tree p2 = constroi((no * 2) + 2, meio + 1, dir);
	arvore[no] = p1 + p2;
	return arvore[no];
}

inline void atualiza_no(int no) {
	int _homem = 0, _elefante = 0, _rato = 0;
	_elefante = arvore[no].homem;
	_rato = arvore[no].elefante;
	_homem = arvore[no].rato;
	arvore[no].homem = _homem;
	arvore[no].elefante = _elefante;
	arvore[no].rato = _rato;
}

void propaga(int no) {
	int p = lz[no] % N_JOGADAS;
	while(p--) {
		atualiza_no((no * 2) + 1);
		lz[(no * 2) + 1]++;
		atualiza_no((no * 2) + 2);
		lz[(no * 2) + 2]++;
	}
	lz[no] = 0;
}

Tree consulta(int no, int l, int r, int esq, int dir) {
	if(l > dir || r < esq)
		return Tree();
	else if(l >= esq && r <= dir)
		return arvore[no];
	int meio = (l + r)/2;
	propaga(no);
	Tree p1 = consulta((no * 2) + 1, l, meio, esq, dir);
	Tree p2 = consulta((no * 2) + 2, meio + 1, r, esq, dir);
	return p1 + p2;
}

Tree atualiza(int no, int l, int r, int esq, int dir) {
	if(l > dir || r < esq) {
		return arvore[no];
	}
	else if(l >= esq && r <= dir) {
		atualiza_no(no);
		lz[no]++;
		return arvore[no];
	}
	int meio = (l + r)/2;
	propaga(no);
	Tree p1 = atualiza((no * 2) + 1, l, meio, esq, dir);
	Tree p2 = atualiza((no * 2) + 2, meio + 1, r, esq, dir);
	arvore[no] = (p1 + p2);
	return arvore[no];
}

int main() {
	int n, m, a, b;
	char c;
	while(scanf("%d %d", &n, &m) == 2) {
		constroi(RAIZ, 0, n - 1);
		while(m--) {
			getchar();
			scanf("%c %d %d", &c, &a, &b);
			a--; b--;
			if(c == 'M') {
				atualiza(RAIZ, 0, n - 1, a, b);
			} else if(c == 'C') {
				Tree res = consulta(RAIZ, 0, n - 1, a, b);
				printf("%d %d %d\n", res.homem, res.elefante, res.rato);			
			}
		}
		printf("\n");
	}
	return 0;
}
