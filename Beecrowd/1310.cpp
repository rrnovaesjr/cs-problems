#include <bits/stdc++.h>
#define N 54

using namespace std;

int R[N];

int Cdia;

int L(int n) {
	int LSoFar = 0;
	int AbsoluteL = 0;
	for(int i = 0; i < n; i++) {
		LSoFar += (R[i] - Cdia);
		if(LSoFar < 0) {
			LSoFar = 0;
		}
		if(AbsoluteL < LSoFar) {
			AbsoluteL = LSoFar;
		}
	}
	return AbsoluteL;
}

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		scanf("%d", &Cdia);
		for(int i = 0; i < n; i++) {
			scanf("%d", &R[i]);
		}
		printf("%d\n", L(n));
	}
	
	return 0;
}
