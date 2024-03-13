#include <bits/stdc++.h>
#define MAX_N 21
#define MAX_P 40

using namespace std;

int N, P;

vector<int> times;

vector<int> amounts;

int C[MAX_N][MAX_P];

int calculate(int n, int p) {
	
	int &c = C[n][p];
	
	if (c != -1) {
		return c;
	}
	
	if (n == 0 || p == 0) {
		c = 0;
		return 0;
	}
	
	if (p < amounts[n - 1]) {
		return (c = calculate(n - 1, p));
	}
	
	int t1 = calculate(n - 1, p - amounts[n - 1]) + times[n - 1];
	int t2 = calculate(n - 1, p);
	
	c = max(t1, t2);
	
	return c;
}

int main() {
	while(scanf("%d", &N) == 1 && N) {
		scanf("%d", &P);
		times.clear();
		amounts.clear();
		for (int i = 0; i < N; i++) {
			int time, amount;
			scanf("%d %d", &time, &amount);
			times.push_back(time);
			amounts.push_back(amount);
		}
		
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= P; j++) {
				C[i][j] = -1;
			}
		}
		
		printf("%d min.\n", calculate(N, P));
	}
	return 0;
}
