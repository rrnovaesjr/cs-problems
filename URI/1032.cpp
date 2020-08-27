#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX_N 3501*100

using namespace std;

vector<int> load_primes () {
	bool l[MAX_N + 1];
	memset(l, false, sizeof l);
	vector<int> M;
	for (int i = 2; i <= MAX_N; i++) {
		if (!l[i]) {
			for (int j = 2*i; j <= MAX_N; j += i) {
				l[j] = true;
			}
		}
	}
	for (int i = 2; i <= MAX_N; i++) {
		if (!l[i]) {
			M.push_back(i);
		} 
	}
	return M;
}

int k;

int josephus (int n, vector<int>::iterator k) {
	if (n == 1) {
		return 1;
	}
	int safePosition = (josephus(n - 1, k + 1) + (*k - 1)) % n + 1;
	return safePosition;
}

int main() {
	int n;
	vector<int> M = load_primes();
	while (scanf("%d", &n) == 1 && n) {
		k = 0;
		printf("%d\n", josephus(n, M.begin()));
	}
	return 0;
}
