#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T, N, pi, pj, i, nHigh, nLow, c;
	scanf("%d", &T);
	
	for(c = 1; c <= T; c++) {
		scanf("%d", &N);
		
		nHigh = 0;
		nLow = 0;
		scanf("%d", &pi);
		for(i = 0; i < N - 1; i++) {
			scanf("%d", &pj);
			if(pi < pj)
				nHigh++;
			else if(pi > pj)
				nLow++;
			pi = pj;
		}
		
		printf("Case %d: %d %d\n", c, nHigh, nLow);
	}

	return 0;
}
