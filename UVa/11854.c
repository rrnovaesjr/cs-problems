#include <stdio.h>

void ordena(int *lados) {
	int i, j, aux;
	for(i = 2; i >= 1; i--) {
		for(j = 0; j < i; j++) {
			if(lados[j] > lados[j + 1]) {
				aux = lados[j];
				lados[j] = lados[j + 1];
				lados[j + 1] = aux;
			}
		}
	}
}

int main(void) {
	int lados[3], aux;
	
	while(scanf("%d %d %d", &lados[0], &lados[1], &lados[2]) == 3 && (lados[0] || lados[1] || lados[2])) {
		ordena(lados);
		if(lados[2] * lados[2] == lados[0] * lados[0] + lados[1] * lados[1])
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
