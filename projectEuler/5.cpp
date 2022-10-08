#include <bits/stdc++.h>

using namespace std;

unordered_set<int> primes;

unordered_map<int, int> facturate_numbers(int k) {
    unordered_map<int, int> factors;
    int n = k;
    for (int prime : primes) {
        factors[prime] = 0;
        while (n % prime == 0 && n > 1) {
            factors[prime]++;
            n /= prime;
        } 
    }
    return factors;
}

int main() {
    int k = 20;
    bool shouldVisit[k];
    for (int i = 0; i <= k; i++) {
        shouldVisit[i] = true;
    } 
    shouldVisit[0] = false;
    shouldVisit[1] = false;
    for (int i = 2; i <= k; i++) {
        while (!shouldVisit[i]) {
            i++;
        }
        for (int j = 2; i * j <= k; j++) {
            shouldVisit[i * j] = false;
        }
        
    }
    
    for (int i = k; i >= 0; i--) {
        if (shouldVisit[i]) {
            primes.insert(i);
        }
    }

    unordered_map<int, int> required_factors;

    for (int n = 2; n <= k; n++) {
        auto factors = facturate_numbers(n);

        for (pair<int, int> f : factors) {
            if (required_factors.find(f.first) == required_factors.end() || required_factors[f.first] < f.second) {
                required_factors[f.first] = f.second;
            }
        }
    }

    int result = 1;

    for (pair<int, int> f : required_factors) {
        while(f.second--) {
            result *= f.first;
        }
    }

    printf("%d\n", result);

    return 0;
}