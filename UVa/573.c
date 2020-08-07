#include <stdio.h>
#include <string.h>
#define MAX_TAM 150
#define N_DADOS 4

#define ALTURA_INICIAL 0
#define DISTANCIA_SUBIDA 1
#define ALTURA_POS_SUBIDA 2
#define ALTURA_POS_DESCIDA 3

double dados[MAX_TAM][N_DADOS];

int calcula(int H, int U, int D, int F, int dia) {
	int i;
	
	dados[0][ALTURA_INICIAL] = 0.0;
	dados[0][DISTANCIA_SUBIDA] = U;
	dados[0][ALTURA_POS_SUBIDA] = U;
	dados[0][ALTURA_POS_DESCIDA] = U - D;
	
	for(i = 1; dados[i - 1][ALTURA_POS_SUBIDA] <= H && dados[i - 1][ALTURA_POS_DESCIDA] >= 0; i++) {
		dados[i][ALTURA_INICIAL] = dados[i - 1][ALTURA_POS_DESCIDA];
		dados[i][DISTANCIA_SUBIDA] =  dados[i - 1][DISTANCIA_SUBIDA] - ((double) U * F/100);
		if(dados[i - 1][DISTANCIA_SUBIDA] - ((double) U * F/100) < 0.0)
			dados[i][DISTANCIA_SUBIDA] =  dados[i - 1][DISTANCIA_SUBIDA];
		else
			dados[i][DISTANCIA_SUBIDA] =  dados[i - 1][DISTANCIA_SUBIDA] - ((double) U * F/100);
		dados[i][ALTURA_POS_SUBIDA] = dados[i][ALTURA_INICIAL] + dados[i][DISTANCIA_SUBIDA];
		dados[i][ALTURA_POS_DESCIDA] = dados[i][ALTURA_POS_SUBIDA] - D;
	}
	
	return i;
}

int main(void) {
	
	int H, U, D, F;
	int dist, altS, altD;
	int dia;
	while(scanf("%d %d %d %d", &H, &U, &D, &F) == 4 && H) {
		memset(dados, 0.0, sizeof dados);	
		dia = calcula(H, U, D, F, 0);
		
		if(dados[dia - 1][ALTURA_POS_SUBIDA] >= H)
			printf("success ");
		else
			printf("failure ");
		printf("on day %d\n", dia);
		
	} 

	return 0;
}
