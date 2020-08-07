#include <stdio.h>
#include <string.h>
#define MAXS 7
#define ONE "one"
#define TWO "two"
#define THREE "three"

int main() {
	int n;
	char number[MAXS];
	
	scanf("%d", &n);
	register int i, j, numd1, numd2, numd3, tam;
	for(i = 0; i < n; i++) {
		scanf("%s", number);
		
		numd1 = 0;
		numd2 = 0;
		numd3 = 0;
		
		for(j = 0; number[j] != '\0'; j++) {
			if(number[j] != ONE[j])
				numd1++;
			if(number[j] != TWO[j])
				numd2++;
			if(number[j] != THREE[j])
				numd3++;
		}

		tam = strlen(number);

		numd1 += abs(tam - strlen(ONE));
		numd2 += abs(tam - strlen(TWO));
		numd3 += abs(tam - strlen(THREE));

		if(numd1 == 1)
			printf("1\n");
		else if(numd2 == 1)
			printf("2\n");
		else if(numd3 == 1)
			printf("3\n");
			
	}
	return 0;
}
