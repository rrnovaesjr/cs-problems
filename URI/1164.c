#include <stdio.h>
#include <math.h>

int main() {
	int N, deu;
	int p[] = { 2, 3, 5, 7, 11, 13, 17, 23, 29, 37, 41, 43, 47, 53, 59 };
	long long int X;
	register long long int resultado;
	
	register int i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%lld", &X);
		
		deu = 0;
		for(j = 0; j < 15 && !deu; j++) {
			resultado = pow(2, p[j] - 1) * (pow(2, p[j]) - 1);
			if(resultado == X) {
				deu = 1;
			}
		}
		
		if(deu)
			printf("%lld eh perfeito\n", X);
		else
			printf("%lld nao eh perfeito\n", X);
	}
	return 0;
}
