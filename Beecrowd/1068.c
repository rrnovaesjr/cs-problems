#include <stdio.h>
#include <stdlib.h>
#define EXP_S 10001

#define AP '('
#define FP ')'

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
	char t = p->p[-- p->topo];
	return t;
}

void insere(Pilha *p, char t) {
	p->p[p->topo++] = t;
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
	char exp[EXP_S];
	register int i, flag;
	Pilha *p;
	while(scanf("%s", exp) == 1) {
		flag = 1;
		p = inicializa();
		for(i = 0; exp[i] != '\0' && flag; i++) {
			if(exp[i] == AP)
				insere(p, exp[i]);
			else if(exp[i] == FP)
				flag = corresponde(desempilha(p), exp[i]);
		}
		flag && tamanho(p) == 0 ? printf("correct\n") : printf("incorrect\n");
		esvazia(p);
	}
	return 0;
}
