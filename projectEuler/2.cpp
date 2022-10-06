#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull F[90];

ull f(int n) {

    if (F[n] != 0) return F[n];

    if (n == 0) {
        return (F[0] = 0);
    }
    if (n == 1) {
        return (F[1] = 1);
    }
    if (n == 2) {
        return (F[2] = 2);
    }
    
    return (F[n] = f(n - 1) + f(n - 2));
    
}


int main() {
    int n = 0;
    
    while (f(n) < 4000000ULL) {
        n++;
    }
    
    ull sum = 0ULL;
    for (int i = 0; i < n; i++) {
        if (f(i) % 2 == 0) {
            sum += f(i); 
        }
    }
    
    printf("%llu\n", sum);

    return 0;
}
