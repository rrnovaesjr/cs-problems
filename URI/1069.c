#include <stdio.h>
#include <stdlib.h>
#define EXP_S 1001

#define AP '<'
#define FP '>'

typedef struct {
	int topo;
	char p[EXP_S];
} Pilha;

Pilha* inicializa() {
	Pilha *p = malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}

int tamanho(Pilha *p) {
	return p->topo;
}

char desempilha(Pilha *p) {
	if(p->topo >= 1) {
		p->topo -= 1;
		char t = p->p[p->topo];
		return t;
	}
	return '.';
}

void insere(Pilha *p, char t) {
	p->p[p->topo] = t;
	p->topo++;
}

void esvazia(Pilha *p) {
	free(p);
}

int corresponde(char a, char b) {
	if(a == AP && b == FP)
		return 1;
	return 0;
}

int main() {
	char ch;
	register int i, cont;
	int t;
	Pilha *p;
	scanf("%d", &t);
	getchar();
	while(t--) {
		cont = 0;
		p = inicializa();
		while(scanf("%c", &ch), ch != '\n') {
			if(ch == AP)
				insere(p, ch);
			else if(ch == FP)
				cont += corresponde(desempilha(p), ch);
		}
		printf("%d\n", cont);
		esvazia(p);
	}
	return 0;
}
