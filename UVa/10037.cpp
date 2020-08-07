#include <bits/stdc++.h>
#define INF -1

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main(void) {

	queue<int> ladoEsquerdo;
	queue<int> ladoDireito;
	int v1, v2, t;
	map<int, vector<int> > instanteResposta;
	vector<int> entrada;
	char sep = '\0';
	int n, c;
	scanf("%d", &c);
	while(c--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &v1);
			entrada.push_back(v1);
		}
		sort(entrada.begin(), entrada.end(), compare);
		for(int i = 0; i < n; i++)
			ladoEsquerdo.push(entrada[i]);
		
		t = 0;
		while(!ladoEsquerdo.empty()) {	
			/*
			* Tira dois da esquerda e vai pra direita (se possível)
			*/
			v1 = ladoEsquerdo.front();
			ladoEsquerdo.pop();
			ladoDireito.push(v1);
			instanteResposta[t].push_back(v1);
			if(!ladoEsquerdo.empty()) {
				v2 = ladoEsquerdo.front();
				ladoEsquerdo.pop();
				ladoDireito.push(v2);
				instanteResposta[t].push_back(v2);
			}
			else {
				v2 = INF;
			}
			t += max(v1, v2);
			/*
			* Tira o mais rápido da direita e retorna pra esquerda
			*/
			if(!ladoEsquerdo.empty()) {
				v1 = ladoDireito.front();
				ladoDireito.pop();
				instanteResposta[t].push_back(v1);
				t += v1;
				ladoEsquerdo.push(v1);
			}
		}
		printf("%c", sep);
		sep = '\n';
		printf("%d\n", t);
		for(map<int, vector<int> >::iterator i = instanteResposta.begin(); i != instanteResposta.end(); i++) {
			printf("%d", i->second.front());
			for(int j = 1; j < i->second.size(); j++) {
				printf(" %d", i->second[j]);
			}
			printf("\n");
		}
		entrada.clear();
		while(!ladoDireito.empty())
			ladoDireito.pop();
		instanteResposta.clear();
	}
	return 0;
}
