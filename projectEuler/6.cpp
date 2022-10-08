#include <bits/stdc++.h>

using namespace std;


int main() {
    int n = 100;

    unsigned long long result = (n*n*n*n)/4 + (n*n*n)/6 - (n*n)/4 - n/6;

    printf("%llu\n", result);
    return 0;
}