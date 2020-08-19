#include <bits/stdc++.h>
#define MAX_N 51

using namespace std;

#define MACHINE_EPS 10e-6

int pd[MAX_N];

vector<unsigned long long int> tower[MAX_N];

inline bool is_perfect_square (unsigned long long int a, unsigned long long int b) {
	long double root = sqrt(a + b);
	unsigned long long int i_root = (unsigned long long int) root;
	return abs(root - i_root) == 0.0;
}

unsigned long long int calculate(int N) {
	if (pd[N]) {
		return pd[N];
	}

	if (N == 1) {
		tower[N].push_back(1ULL);
		return (pd[N] = 1);
	}

	unsigned long long int untilNow = calculate(N - 1);
	bool hasSquareToCheck;
	do {
		hasSquareToCheck = false;
		for (int rod = 1; rod <= N && !hasSquareToCheck; rod++) {
			if (tower[rod].empty()) {
				hasSquareToCheck = true;
			} else if (!tower[rod].empty() && is_perfect_square (untilNow + 1ULL, tower[rod].back())) {
				hasSquareToCheck = true;
				tower[rod].push_back(untilNow);
			}

			if (hasSquareToCheck) {
				untilNow += 1ULL;
				tower[rod].push_back(untilNow);
				break;
			}
		}
	} while (hasSquareToCheck);
	return (pd[N] = untilNow);
}


int main() {
	unsigned long long int output;
	int T, N;
	memset(pd, 0, sizeof pd);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%llu\n", calculate(N));
	}
	return 0;
}
