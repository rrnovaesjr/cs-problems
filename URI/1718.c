#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define CMAX 150000
#define NMAX 12000


int main() {
	int C, N;
	int pizza[CMAX];
	
	scanf("%d %d", &C, &N);
	
	memset(pizza, 0, sizeof pizza);
	
	int i, az;
	for(i = 0; i < N; i++) {
		scanf("%d", &az);
		pizza[az] = 1;
	}
	
	bool deu = false;
	int comeco, cFatia, nAzeitonas;
	
	for(comeco = 0; comeco < C/N && !deu; comeco++) {
		cFatia = 0;
		nAzeitonas = 0;
		deu = true;
		for(i = comeco; (i + 1) % C != comeco && deu; i = (i + 1) % C) {
			cFatia++;
			if(pizza[i])
				nAzeitonas++;
			if(cFatia == C/N) {
				if(nAzeitonas > 1 || nAzeitonas == 0)
					deu = false;
				else
					cFatia = 0, nAzeitonas = 0;
			}
		}
	}
	
	if(deu)
		printf("S\n");
	else
		printf("N\n");
	
	return 0;
}
