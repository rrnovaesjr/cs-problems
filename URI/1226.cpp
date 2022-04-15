#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull count_4s_algarisms(int algarisms) {
    return ((ull) algarisms) * ((ull) pow(9ULL, algarisms - 1ULL));
}

ull count_13s_algarisms(int algarisms) {
    return ((ull) algarisms - 1ULL) * ((ull) pow(9ULL, algarisms - 2ULL));
}

int count_4s(int x) {
    return x >= 4 ? 1 : 0;
}

int count_13s(int x) {
    return x >= 13 ? 1 : 0;
}


ull chinese_floor(ull N) {
    int order = log10(N) + 1;
    ull measure = pow(10, order);
        
    int absolute_4s = (int) N/measure;
    int absolute_13s = (int) (N/(measure/10));
   
    printf("%llu -> %llu %llu %d %d\n", N, count_4s_algarisms(order), count_13s_algarisms(order), absolute_4s, absolute_13s);
    
    return N + count_4s_algarisms(order) + count_13s_algarisms(order) + count_4s(absolute_4s) + count_13s(absolute_13s);
}

int main() {
    ull N;
        
    while (scanf("%llu", &N) == 1) {
        printf("%llu\n", chinese_floor(N));
    }

    return 0;
}
