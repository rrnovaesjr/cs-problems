#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char ch;
	int estado = 1, nPalavras = 0, encontrei = 0;
	while(scanf("%c", &ch) != EOF) {
		switch(estado) {
			case 1:
				if(isalpha(ch))
					encontrei = 1;
				if(!isalpha(ch) && encontrei) {
					estado = 2;
					nPalavras++;
				}
				break;
			case 2:
				if(ch == '\n') {
					printf("%d\n", nPalavras);
					nPalavras = 0;
					encontrei = 0;
				}
				if(isalpha(ch)) {
					estado = 1;
					ungetc(ch, stdin);
				}
				break;
		}
	}
	return 0;
}
