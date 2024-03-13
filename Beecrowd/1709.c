#include <stdio.h>
#include <string.h>
#define NMAX 150000

int cont;

int P;

int pos(int i, int j) {
	if(i == j)
		return 0;
		
	if(j <= P/2)
		return pos(i, 2 * j) + 1;

	return pos(i, 2 * j - P - 1 ) + 1;

}

int main() {
	scanf("%d", &P);
	
	printf("%d\n", pos(1, 2) + 1);

	return 0;
}
