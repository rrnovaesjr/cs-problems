#include <stdio.h>
#include <string.h>
#define N_MAX	 	500
#define INF		10000

int conexoes_paises[N_MAX][N_MAX];

int horas_gastas[N_MAX][N_MAX];

void floyd(int n) {
	register int i, j, k;
	for(k = 0; k < n; k++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(horas_gastas[i][j] > horas_gastas[i][k] + horas_gastas[k][j]) {
					horas_gastas[i][j] = horas_gastas[i][k] + horas_gastas[k][j];
				}
			}
		}
	}
}

int main() {
	int N, E, K, M, u, v;
	register int i, j;
	while((scanf("%d %d", &N, &E) == 2) && (N || E)) {
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				conexoes_paises[i][j] = -1;
				if(i == j)
					horas_gastas[i][j] = 0;
				else
					horas_gastas[i][j] = INF;
			}
		}
	
		for(i = 0; i < E; i++) {
			scanf("%d %d %d", &u, &v, &M);
			u--;
			v--;
			if(conexoes_paises[v][u] != -1) {
				conexoes_paises[u][v] = 0;
				conexoes_paises[v][u] = 0;
				horas_gastas[u][v] = 0;
				horas_gastas[v][u] = 0;
			} else {
				conexoes_paises[u][v] = M;
				horas_gastas[u][v] = M;
			}
		}
	
		floyd(N);
		scanf("%d", &K);
		for(i = 0; i < K; i++) {
			scanf("%d %d", &u, &v);
			u--;
			v--;
			
			if(horas_gastas[u][v] == INF)
				printf("Nao e possivel entregar a carta\n");
			else
				printf("%d\n", horas_gastas[u][v]);
		}
		printf("\n");
	}
	return 0;
}
