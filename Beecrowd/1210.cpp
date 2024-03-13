#include <bits/stdc++.h>
#define MAX_N 2010
#define MAX_M 2010
#define INF 0x3f3f3f3f

using namespace std;

int N, I, M, P;

int F[MAX_N][MAX_M];

int maintance_cost[MAX_M];

int selling_price[MAX_M];

int calculate (int year, int age) {

	if (F[year][age] != -1) {
		return F[year][age];
	}

	if (year == N) {
		return (F[year][age] = 0);
	}

	return F[year][age] = min(calculate(year + 1, 1) + (P - selling_price[age - 1] + maintance_cost[0]), 
		age == M ? INF : calculate(year + 1, age + 1) + maintance_cost[age]);
}

queue<int> recreate_path (int initialAge) {
	
	int age = initialAge;
	queue<int> path;
	
	for (int i = 0; i < N; i++) {
		if (age == M) {
			path.push(i + 1);
			age = 1;
		} else {
			int selling = F[i + 1][1] + P - selling_price[age - 1] + maintance_cost[0];
			int keeping = F[i + 1][age + 1] + maintance_cost[age];
			
			if (selling <= keeping) {
				path.push(i + 1);
				age = 1;
			} else {
				age++;
			}
		}
	}
	
	return path;
}

int main() {
	while (scanf("%d %d %d %d", &N, &I, &M, &P) == 4) {
		
		memset (F, -1, sizeof F);
	
		for (int i = 0; i < M; i++) {
			scanf("%d", &maintance_cost[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &selling_price[i]);
		}
		
		
		printf("%d\n", calculate(0, I));
		
		queue<int> soldYears = recreate_path(I);
		
		if (!soldYears.empty()) {
			printf("%d", soldYears.front());
			soldYears.pop();
			while(!soldYears.empty()) {
				printf(" %d", soldYears.front());
				soldYears.pop();
			}
		} else {
			printf("0");
		}
		printf("\n");
		
	}
	return 0;
}
