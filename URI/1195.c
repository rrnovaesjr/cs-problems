#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
	int n;
	struct arv *esq, *dir;
} Arvore;

Arvore* busca(Arvore** raiz, Arvore*** posIns, int val) {
	if((*raiz) != NULL) {
		if((*raiz)->n == val) {
			return (*raiz);
		}		
		else if((*raiz)->n > val) {
			*posIns = &(*raiz)->esq;
			return busca(&(*raiz)->esq, posIns, val);
		}
		else {
			*posIns = &(*raiz)->dir;
			return busca(&(*raiz)->dir, posIns, val);
		}
	}
	return NULL;
}

int insere(Arvore** raiz, int val) {
	Arvore** posIns;

	posIns = raiz;
	if(busca(raiz, &posIns, val) == NULL) {
		(*posIns) = (Arvore *) malloc(sizeof(Arvore));
		(*posIns)->n = val;
		(*posIns)->esq = (*posIns)->dir = NULL;
		return 1;
	}
	return 0;
}

void preOrdem(Arvore* raiz) {
	if(raiz != NULL) {
		printf(" %d", raiz->n);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void inOrdem(Arvore* raiz) {
	if(raiz != NULL) {
		inOrdem(raiz->esq);
		printf(" %d", raiz->n);
		inOrdem(raiz->dir);
	}
}

void posOrdem(Arvore* raiz) {
	if(raiz != NULL) {
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf(" %d", raiz->n);
	}
}

void destroi(Arvore* raiz) {
	if(raiz != NULL) {
		destroi(raiz->esq);
		destroi(raiz->dir);
		free(raiz);
	}
}

int main(void) {
	int C, N, v, i;	
	Arvore *r;

	i = 0;	
	scanf("%d", &C);
	while(C--) {
		r = NULL;
		scanf("%d", &N);

		while(N--) {
			scanf("%d", &v);
			insere(&r, v);
		}

		printf("Case %d:\n", ++i);
		printf("Pre.:");
		preOrdem(r);
		printf("\n");

		printf("In..:");
		inOrdem(r);
		printf("\n");

		printf("Post:");
		posOrdem(r);
		printf("\n\n");
		destroi(r);
	}
	return 0;
}
