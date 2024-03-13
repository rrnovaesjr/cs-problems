#include <bits/stdc++.h>

using namespace std;

map<long long, long long> numbers;
unsigned long long n;

int main() {
	scanf("%llu", &n);
	long long q;
	while(n--) {
		scanf("%lld", &q);
		numbers[q]++;
	}
	for(map<long long, long long>::iterator i = numbers.begin(); i != numbers.end(); i++) {
		printf("%lld aparece %lld vez(es)\n", i->first, i->second);
	}
	return 0;
}
