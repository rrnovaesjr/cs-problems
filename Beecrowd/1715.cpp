#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int main() {
	int N, M, u, nJogadores = 0;
	
	scanf("%d %d", &N, &M);

	bool marcouEmTodas;
	for(int i = 0; i < N; i++) {

		marcouEmTodas = true;

		for(int j = 0; j < M; j++) {
			scanf("%d", &u);
			if(u == 0)
				marcouEmTodas = false;
		}

		if(marcouEmTodas)
			nJogadores++;
	}
	
	printf("%d\n", nJogadores);

	return 0;
}
