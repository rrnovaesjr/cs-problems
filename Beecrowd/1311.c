#include <stdio.h>

int main() {
	int S, B, L, R, i, lI, rI;
		
	while(scanf("%d %d", &S, &B), S || B) {
		
		lI = S + 1;
		rI = 1;
		for(i = 0; i < B; i++) {
			scanf("%d %d", &L, &R);
			
			if(L <= lI)
				lI = L - 1;
			if(R >= rI)
				rI = R + 1;

			lI > 0 ? printf("%d ", lI) : printf("* ");
			rI <= S ? printf("%d\n", rI) : printf("*\n");

		}
		printf("-\n");		
	}
	return 0;
}
