#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX 30

unsigned long long int tabela[100000];

unsigned long long int altera(unsigned long long int n) {
	char str[STR_MAX];
	sprintf(str, "%llu", n);
	int tam = strlen(str);
	int i;
	for(i = 0; i < tam; i++) {
		if(str[i] == '1')
			if(str[i + 1] == '3')
				str[i + 1] = '4';
		if(str[i] == '4')
			str[i] = '5';
	}
	return n;
}

unsigned long long int calcula(unsigned long long int n) {
	if(tabela[n] == 0) {
		unsigned long long int nn = altera(tabela[n - 1] + 1);
		tabela[n] = nn;
	}
	return tabela[n];

}

int main() {
	unsigned long long int n;
	memset(tabela, 0, sizeof tabela);
	while(scanf("%llu", &n) == 1) {
		printf("%llu\n", calcula(n));
	}
	return 0;	
}
