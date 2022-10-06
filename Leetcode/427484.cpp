#include <bits/stdc++.h>

using namespace std;

bool isDivisible(string s, string t) {
    if (s.size() % t.size() != 0) return false;

    string concT = "" + t;
    
    while (concT.size() < s.size()) {
        concT = concT + t;
    }
    return concT == s;
}

int findSmallestDivisor(string s, string t) {
    if (!isDivisible(s, t)) {
        return -1;
    }
    
    string smallest = "";
    
    for (int i = 0; i < (int) t.size(); i++) {
        smallest = smallest + t[i];
        if (isDivisible(t, smallest)) {
            return (int) smallest.size();
        }
    }
    return -1;

}

int main() {
    string s, t;
    
    cin >> s >> t;
    cout << findSmallestDivisor(s, t) << endl;       

    return 0;
}
