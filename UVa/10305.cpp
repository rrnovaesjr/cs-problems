#include <bits/stdc++.h>
#define N 102

using namespace std;

vector<int> ladj[N];

int visitado[N];

vector<int> lambda;

void dfs(int u) {
	visitado[u] = 1;
	int v;
	for(int i = 0; i < ladj[u].size(); i++) {
		v = ladj[u][i];
		if(!visitado[v])
			dfs(v);
	}
	lambda.push_back(u);
}

void imprime() {
	if(!lambda.empty()) {
		printf("%d", lambda.back());
		lambda.pop_back();
		while(!lambda.empty()) {
			printf(" %d", lambda.back());
			lambda.pop_back();
		}
	}
	printf("\n");
}

int main(void) {
	int m, n;
	int u, v;
	while(scanf("%d %d", &n, &m) == 2 && (m || n)) {
		memset(visitado, 0, sizeof(int) * (n + 1));
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			ladj[u].push_back(v);
		}
		for(u = 1; u <= n; u++)
			if(!visitado[u])
				dfs(u);
		imprime();
		for(u = 0; u <= n; u++)
			ladj[u].clear();
	}
	return 0;
}