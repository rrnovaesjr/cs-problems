
#include <bits/stdc++.h>
#define N 300
#define MAX_N(t) (2*t*(2*t+1))

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

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

    for (int d = 0; d < 4; d++) {
        int x = u.first + dx[d];
        int y = u.second + dy[d];

        if ((x >= 0 && x < 2 * n ) &&
            (y >= 0 && y < 2 * n + 1) &&
            graphT[P(u.first, u.second)].find(P(x, y)) == graphT[P(u.first, u.second)].end()) 
        {
            adj.push_back(make_pair(x, y));
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
    int evenLine, rj;
    while (scanf("%d", &n) == 1) {
        
        graphT.clear();
        graphT.resize(MAX_N(n));

        for (register int i = 0; i < 2 * n - 1; i++) {
            for (register int j = 0; j < n; j++) {
                cin >> b;
                rj = 2*j + i % 2;     
                if (b == 'H') {
                    insertEdge(P(i, (rj)), P((i+1), (rj)));
                    insertEdge(P(i, rj+1), P((i+1), (rj+1)));
                } else {
                    insertEdge(P(i, (rj)), P(i, (rj+1)));
                    insertEdge(P((i+1), (rj)), P((i+1), (rj+1)));
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