#include <bits/stdc++.h>
#define MAXN 5010
#define BASE 3

using namespace std;

string fita;

char base[BASE] = { 'N', 'O', 'P' };

bool verifica(int i, int k, int salto) {
	string busca
	for(int i = 0; i < fita.size(); i += salto) {
		if(fita.substr(i, salto)
	}
}

bool genoma(int n, int cont, int i) {
	if(n == cont) {
		return true;
	}
	tenta
}

int main(void) {
	int n;
	
	while(scanf("%d", &n), n) {
		imprimeGenoma(n, 0, 0);
	}
	return 0;
}
