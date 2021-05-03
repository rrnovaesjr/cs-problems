
#include <bits/stdc++.h>
#include <bitset>
#define N 300
#define MAX_N(t) (2*t*(2*t+1))

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int n;

bitset<4 * N> g[4 * N + 2];

#define ROWS (4*n)
#define COLUMNS (2*(2*n+1))

void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));
    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        for(int d = 0; d < 4; d++) {
            int x = u.first + dx[d], y = u.second + dy[d];
            if ((x >= 0 && x < ROWS) &&
                (y >= 0 && y < COLUMNS) && 
                !g[x][y])
            {
                Q.push(make_pair(x, y));
                g[x][y] = 1;
            }
        }

    
    }
}

int main() {

    char b;
    int evenLine, bi, bj;
    while (scanf("%d", &n) == 1) {
        
        for (int i = 0; i < ROWS; i++) {
            g[i].reset();
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b;
                evenLine = i % 2;
                bi = 2*i+1;
                bj = 2*(2*j + evenLine) + 1;
                if (b == 'H') {
                    g[bi][bj-1] = 1;
                    g[bi][bj] = 1;
                    g[bi][bj+1] = 1;
                    g[bi][bj+2] = 1;
                } else {
                    g[bi-1][bj] = 1;
                    g[bi][bj] = 1;
                    g[bi+1][bj] = 1;
                    g[bi+2][bj] = 1;
                }
            }
        }

        int cfcs = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (!g[i][j]) {
                    bfs(i, j);
                    cfcs++;
                }
            }
        }

        printf("%d\n", cfcs-1);

    }

    return 0;
}