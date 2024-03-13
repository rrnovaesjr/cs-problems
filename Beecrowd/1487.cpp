#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_N 110
#define MAX_T 610

int N, T;

int valueByAttraction[MAX_N];

int timeSpentByAttraction[MAX_N];

int SCORE[MAX_T];

int calculate_score (int remainingTime) {
	if (SCORE[remainingTime]) {
		return SCORE[remainingTime];
	}

	if (remainingTime == 0) {
		return (SCORE[remainingTime] = 0);
	}
	
	int result = 0;
	for (int j = 0; j < N; j++) {
		if (timeSpentByAttraction[j] <= remainingTime) {
			result = max( calculate_score(remainingTime - timeSpentByAttraction[j]) + valueByAttraction[j], result);
		}
	}
	return (SCORE[remainingTime] = result);
}

int main() {
	for (int h = 1; scanf("%d %d", &N, &T) == 2 && (N || T); h++) {
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &timeSpentByAttraction[i], &valueByAttraction[i]);
		}
		printf("Instancia %d\n%d\n\n", h, calculate_score(T));
		memset (SCORE, 0, sizeof SCORE);
	}
	return 0;
}
