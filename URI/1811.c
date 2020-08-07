#include <stdio.h>
#include <stdlib.h>
#define N_MAX 1000
#define M_MAX 100
#define FATORES 3

#define RISCO 0
#define V_DIF 1
#define V_FIN 2

int _OBTEM_RESPOSTA[N_MAX][FATORES];

int _DADOS_OBSERVADOS[N_MAX][M_MAX];

typedef struct {
	int pilha[N_MAX];
	int topo;
} Pilha;

void inicializa(Pilha* p) {
	p->topo = 0;
}

void empilha(Pilha* p, int v) {
	p->pilha[p->topo] = v;
	p->topo++;
}

int desempilha(Pilha* p) {
	int v = p->pilha[p->topo--];
	return v;
}

int vazia(Pilha* p) {
	if(p->topo > 0)
		return 0;
	return 1;
}

void calcula(int n, int m) {
	int i, j, nAumentos, memoria_aumento, inicio, memoria_inicio, fim;
	for(i = 0; i < n; i++) {
		nAumentos = memoria_aumento = inicio = memoria_inicio = fim = 0;
		for(j = 1; j < m; j++) {
			if(_DADOS_OBSERVADOS[i][j] > _DADOS_OBSERVADOS[i][j - 1]) {
				nAumentos++;
			}
			else if(nAumentos >= memoria_aumento) {
				memoria_aumento = nAumentos;
				memoria_inicio = inicio;
				fim = j - 1;
				inicio = j;
				nAumentos = 0;
			}
			else {
				nAumentos = 0;
				inicio = j;
			}
		}
		_OBTEM_RESPOSTA[i][RISCO] = memoria_aumento;
		_OBTEM_RESPOSTA[i][V_DIF] = _DADOS_OBSERVADOS[i][fim] - _DADOS_OBSERVADOS[i][memoria_inicio];
		_OBTEM_RESPOSTA[i][V_FIN] = _DADOS_OBSERVADOS[i][fim];
	}
}

int main(void) {

	int n, m, i, j, maior, caso, tie = 0;
	Pilha p;
	while(scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);

		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				scanf("%d", &_DADOS_OBSERVADOS[i][j]);		

		calcula(n, m);
		inicializa(&p);

		/* Caso 1 */
		maior = 0;
		for(i = 1; i < n; i++)
			if(_OBTEM_RESPOSTA[i][RISCO] > _OBTEM_RESPOSTA[maior][RISCO])
				maior = i;

		for(i = 0; i < n; i++)
			if(i != maior && _OBTEM_RESPOSTA[i][RISCO] == _OBTEM_RESPOSTA[maior][RISCO])
				empilha(&p, i);
	
		if(vazia(&p)) {
			printf("%d\n", maior + 1);
		}

		continue;
		/* Caso 2 */
		
		maior = 0;
		for(i = 1; i < n; i++)
			if(_OBTEM_RESPOSTA[i][RISCO] > _OBTEM_RESPOSTA[maior][RISCO])
				maior = i;

		for(i = 0; i < n; i++)
			if(i != maior && _OBTEM_RESPOSTA[i][RISCO] == _OBTEM_RESPOSTA[maior][RISCO])
				empilha(&p, i);
	
		if(vazia(&p)) {
			printf("%d\n", maior + 1);
		}
			
		
		continue;	
	}

	return 0;
}

