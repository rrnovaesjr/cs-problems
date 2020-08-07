#include <stdio.h>

int mdc(int a, int b) {
	if(b == 0)
		return a;
	return mdc(b, a % b);
}

int main(void) {
	int N;
	int F1, F2, div, a, b;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &F1, &F2);
		
		if(F1 > F2) {
			a = F1;
			b = F2;	
		}
		else {
			a = F2;
			b = F1;
		}
		
		div = mdc(a, b);
				
		printf("%d\n", div);
	
	}
	return 0;
}
