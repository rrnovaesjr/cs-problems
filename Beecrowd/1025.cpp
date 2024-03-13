#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> marbles;
	int N, Q, target, caseCount = 1;
	
	while (scanf("%d %d", &N, &Q) == 2 && (N || Q)) {
		marbles = vector<int>(N);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &marbles[i]);
		}
				
		sort(marbles.begin(), marbles.end(), less<int>());
		
		printf("CASE# %d:\n", caseCount);
		while (Q--) {
			scanf("%d", &target);
			
			auto it = equal_range (marbles.begin(), marbles.end(), target, less<int>());
			
			if (it.first == it.second) {
				printf ("%d not found\n", target);
			} else {
				printf("%d found at %d\n", target, (it.first - marbles.begin()) + 1);
			}
		}
		
		caseCount++;
		marbles.clear();
	}
	
	return 0;
}
