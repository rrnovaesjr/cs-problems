#include <stdio.h>
#include <string.h>
#define MAXN 100505

int L[MAXN];

int v[MAXN];

int c, n;

int max(int a, int b) {
	return a > b ? a : b;
}

int maxL(int i) {
	if(i == 1)
		return 0;

	if(L[i] != -1)
		return L[i];

	L[i] = maxL(i - 1);
	
	register int j;
	for(j = 1; j < i; j++)
		L[i] = max( maxL(j) + v[i] - v[j] - c, L[i] );
	
	return L[i];
}

int main(void) {
	scanf("%d %d", &n, &c);
		
	memset(L, -1, sizeof(int) * (n + 1));

	register int i;
	for(i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	
	printf("%d\n", maxL(n));
	return 0;
}
