
#include <bits/stdc++.h>
#define N 300
#define MAX_N(t) (4*t*(t+1))

using namespace std;

int n;

vector<unordered_set<int>> graphT(MAX_N(N));

#define P(i,j) (i * (2 * n + 1) + j)

inline void insertEdge(int u, int v) {
    #ifdef TRACE
    printf("Blocking (%d) to (%d)\n", u, v);
    #endif
    graphT[u].insert(v);
    graphT[v].insert(u);
}

inline vector<pair<int, int>> neighbours(pair<int, int> u) {
    vector<pair<int, int>> adj;

    for (register int i = -1; i <= 1; i+= 2) {
        if (u.first + i >= 0                                                                                            // vertical position should be valid
            && u.first + i < 2 * n                                                                                      // vertical position should be valid
            && graphT[P(u.first, u.second)].find(P((u.first + i), u.second)) == graphT[P(u.first, u.second)].end())        // vertical position should not be blocked
        {
            adj.push_back(make_pair(u.first + i, u.second));
        }
    }

    for (register int j = -1; j <= 1; j+= 2) {
        if (u.second + j >= 0                                                                                           // horizontal position should be valid
            && u.second + j < 2 * n + 1                                                                                 // horizontal position should be valid
            && graphT[P(u.first, u.second)].find(P(u.first, (u.second + j))) == graphT[P(u.first, u.second)].end())     // horizontal position should not be blocked
        {
            adj.push_back(make_pair(u.first, u.second + j));
        }
    }

    return adj;
}

unordered_set<int> visited;

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    visited.insert(P(x, y));
    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        vector<pair<int, int>> adj = neighbours(u);
    
        for (pair<int, int> v : adj) {
            if (visited.find(P(v.first, v.second)) == visited.end()) {
                Q.push(v);
                visited.insert(P(v.first, v.second));
            }
        }

    }
}

int main() {

    char b;
    int evenLine;
    while (scanf("%d", &n) == 1) {
        
        graphT.clear();
        graphT.resize(MAX_N(n));
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b;
                evenLine = i % 2;     
                if (b == 'H') {
                    insertEdge(P(i, (j*2 + evenLine)), P((i+1), (j*2 + evenLine)));
                    insertEdge(P(i, j*2+1 + evenLine), P((i+1), (j*2+1 + evenLine)));
                } else {
                    insertEdge(P(i, (j*2 + evenLine)), P(i, (j*2+1 + evenLine)));
                    insertEdge(P((i+1), (j*2 + evenLine)), P((i+1), (j*2+1 + evenLine)));
                }
            }
        }

        #ifdef TRACE
        for (int i = 0; i < MAX_N(n); i++) {
            cout << i;
            for (int j : graphT[i]) {
                cout << ' ' << j;
            }
            cout << endl;
        }
        #endif

        visited.clear();
        int cfcs = 0;
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n + 1; j++) {
                if (visited.find(P(i, j)) == visited.end()) {
                    bfs(i, j);
                    cfcs++;
                }
            }
        }

        printf("%d\n", cfcs-1);

    }

    return 0;
}