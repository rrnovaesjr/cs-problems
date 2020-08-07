#include <stdio.h>
#include <string.h>
#define N 300500

int abs(int a) {
	return a >= 0 ? a : -1 * a;
}

int main() {
	char *jogadores[2];
	jogadores[0] = "Marcelo";
	jogadores[1] = "Carlos";
	
	int n, i, j, nTrocas, aux, v[N];
	while(scanf("%d", &n), n) {
		nTrocas = 0;
		for(i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		
		i = 1;
		while(i <= n) {
			if(v[i] == i) {
				i++;
				continue;	
			}
			nTrocas += (2 * abs(v[i] - i) - 1);
			j = v[i];
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
		printf("%s\n", nTrocas % 2 == 0 ? jogadores[1] : jogadores[0]);
	}
	return 0;
}
