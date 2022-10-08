#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(int n) {
    string ns = to_string(n);
    
    for (int i = 0, j = ns.size() - 1; i < j; i++, j--) {
        if (ns[i] != ns[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int begin = 100;
    int end = 999;
    int largest = 0;
    for (int i = begin; i <= end; i++) {
        for (int j = i; j <= end; j++) {
            if (is_palindrome(i * j)) {
                largest = max(largest, i * j);
            }
        }
    }
    
    printf("%d\n", largest);
    
    return 0;
}
