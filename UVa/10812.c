#include <stdio.h>

int abs(int v) {
	return v >= 0 ? v : -v;
}

int main() {
	int s, d, t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &s, &d);
		a = (s + d)/2;
		b = abs(s - d)/2;
		
		if(a + b != s || abs(a - b) != d)
			printf("impossible\n");
		else
			if(a > b)
				printf("%d %d\n", a, b);
			else
				printf("%d %d\n", b, a);
	
	}

	return 0;
}
