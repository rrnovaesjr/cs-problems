#include <bits/stdc++.h>

using namespace std;

int p2(int n) {
    return n*n;
}

int main() {

    for (int x = 1; x <= 499; x++) {
        for (int y = x + 1; y <= 500; y++) {
            int c = 1000 - x - y;

            if (p2(x) + p2(y) == p2(c)) {
                printf("%d\n", x * y * c);
                return 0;
            }
        }
    }

    return 0;
}