#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXA 100050
#define MAXB 10050

bool isSubSequence(char* str1, char* str2, int m, int n, int i) {
	register int cont = 0;
	register j;
	for(j = 0; cont < m * i && j < n; j++)
		if(str1[ cont / i] == str2[j])
			cont++;
	if(cont == m * i)
			return true;
	return false;
}

int main() {
	int T;
	char A[MAXA], B[MAXB];
	register int esq, dir, meio, maxi, tamA, tamB;
	bool res;
	scanf("%d", &T);
	while(T--) {
	    scanf("%s %s", A, B);
		tamA = strlen(A);
		tamB = strlen(B);
				
		esq = 0;
		dir = tamA/tamB + 1;

		if( !isSubSequence(B, A, tamB, tamA, 1) ) {
			printf("0\n");
			continue;
		}
		maxi = 0;
		while(!(dir == esq + 1)) {
			meio = (esq + dir)/2;
			if( isSubSequence(B, A, tamB, tamA, meio) ) {
				maxi = maxi > meio ? maxi : meio; 
				esq = meio;
			}
			else
				dir = meio;
		}
		printf("%d\n", maxi);
	}

	return 0;
}

