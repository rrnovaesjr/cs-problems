#include <bits/stdc++.h>

using namespace std;

int main() {
    int max;
    int sum = 0;
    scanf("%d", &max);
    for (int i = 0; i < max; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
