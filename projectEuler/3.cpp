#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull N = 600851475143;
    ull limit = (ull) sqrt(N);
    bool shouldVisit[limit + 2];
    
    for (ull i = 0ULL; i <= limit; i++) {
        shouldVisit[i] = true;
    }  
    for (ull i = 2ULL; i <= limit; i++) {
        while (!shouldVisit[i]) {
            i++;
        }
        for (ull j = 2ULL; i * j <= limit; j++) {
            shouldVisit[i * j] = false;
        }
        
    }
    
    for (ull i = limit; i >= 0; i--) {
        if (shouldVisit[i] && N % i == 0) {
            printf("%llu\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
