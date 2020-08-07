#include <bits/stdc++.h>
#define N_CHARS 30

using namespace std;

int valor(char ch) {
	if(isalpha(ch))
		return tolower(ch) - 'a' + 1;
	return 0;
}

int unival(char * val) {
	int i;
	int tam;
	int total;
	do {
		total = 0;
		tam = strlen(val);
		for(i = 0; i < tam; i++)
			total += val[i] - '0';
		sprintf(val, "%d", total);
	} while(strlen(val) != 1);
	return val[0] - '0';
}

int main(void) {
	string nomeA, nomeB;
	string valA, valB;
	int totalA, totalB, aux;
	int i, tamA, tamB;
	char auxA[N_CHARS], auxB[N_CHARS];	
	while(getline(cin, nomeA) && getline(cin, nomeB)) {
		totalA = 0;
		totalB = 0;
		tamA = nomeA.size();
		tamB = nomeB.size();
		for(i = 0; i < tamA; i++)
			totalA += valor(nomeA[i]);
		for(i = 0; i < tamB; i++)
			totalB += valor(nomeB[i]);
		
		sprintf(auxA, "%d", totalA);
		sprintf(auxB, "%d", totalB);
		
		tamA = unival(auxA);
		
		tamB = unival(auxB);
		
		if(tamA > tamB) {
			aux = tamB;
			tamB = tamA;
			tamA = aux;
		}
		
		printf("%.2lf %%\n", (100.0 * tamA/tamB));
		
	}
	return 0;
}
