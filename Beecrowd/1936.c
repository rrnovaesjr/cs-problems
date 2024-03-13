#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100000
#define MAXC 10

int F[MAXN];

int fat(int n) {
	if(n == 0)
		return 1;
		
	if(F[n] != -1)
		return F[n];

	return (F[n] = n * fat(n - 1));
}

int kPossivel(int n, int soma) {
	int j;

	if(n == soma)
		return 0;
	
	j = 0;
	while(fat(j) + soma <= n)
		j++;

	j--;
	return kPossivel(n, fat(j) + soma) + 1;
}

int main() {
	memset(F, -1, sizeof F);
	
	int n;
	
	scanf("%d", &n);

	printf("%d\n", kPossivel(n, 0));
	return 0;
}
