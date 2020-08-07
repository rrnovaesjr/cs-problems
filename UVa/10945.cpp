#include <bits/stdc++.h>

using namespace std;

bool p(string s) {
	for(int i = 0, j = s.size() - 1; i <= j; i++, j--) {
		if(s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	string leitura;
	string teste = "";
	while(getline(cin, leitura) && leitura != "DONE") {
		for(int i = 0; i < leitura.size(); i++) {
			if(isalpha(leitura[i])) {
				teste += tolower(leitura[i]);
			}
		}
		if(p(teste)) {
			printf("You won't be eaten!\n");
		}
		else {
			printf("Uh oh..\n");
		}
		teste.clear();
	}
	return 0;
}	
