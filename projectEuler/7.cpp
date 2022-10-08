#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;


ull kth_prime(int k) {

    ull left = 2ULL, right = 2ULL;
    set<ull> primes;
    do {
        ull limit = left * right;
        for (ull i = left; i <= limit; i++) {
            primes.insert(i);
        }

        for (ull i = 2ULL; i <= limit; i++) {
            for (ull j = 2ULL; j * i <= limit; j++) {
                primes.erase(i * j);
            }
        }

        left = right;
        right*=2ULL;
    } while (primes.size() < k);

    vector<ull> ordered_primes;
    copy(primes.begin(), primes.end(), back_inserter(ordered_primes));
    return ordered_primes[k - 1];
}

int main() {
    printf("%llu\n", kth_prime(10001));

    return 0;
}