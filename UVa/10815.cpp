#include <bits/stdc++.h>

using namespace std;

int main() {
	map<string, int> arvore;
	
	char ch;
	string leitura;
	int estado;
	
	leitura = "";
	estado = 0;
	while(estado != 3) {
		cin >> ch;
		
		if(!isalpha(ch) && leitura != "")
			estado = 1;
		else if(!isalpha(ch) && leitura == "")
			continue;
		else if(ch == EOF)
			estado = 2;
		
		switch(estado) {
			case 0:
				leitura += tolower(ch);
				break;
			case 1:
				estado = 0;
				arvore[leitura]++;
				leitura.clear();
				break;
			case 2:
				estado = 3;
				arvore[leitura]++;
				leitura.clear();
				break;
		}
	}

	for(map<string, int>::iterator i = arvore.begin(); i != arvore.end(); i++)
		cout << i->first << endl;
	arvore.clear();
	return 0;
}
