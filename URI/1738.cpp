#include <bits/stdc++.h>
#define MAX_N 203
#define N_COMPANIES ('z' - 'a' + 1)
#define COMPANY_INDEX(c) (c - 'a')

using namespace std;

int d[MAX_N][MAX_N][N_COMPANIES];

struct Node {
    int v;
    char company;
    
    Node() {}
    
    Node(int v, char company): v(v), company(company) {}
};

vector<Node> G[MAX_N];

void bfs(int s) {
    queue<pair<int, char>> Q;
    
    for (auto v : G[s]) {
        Q.push(make_pair(s, v.company));
    }
    
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        
        
        for (auto v : G[u.first]) {
            if (!d[s][v.v][COMPANY_INDEX(u.second)] && v.company == u.second) {
                Q.push(make_pair(v.v, u.second));
                d[s][v.v][COMPANY_INDEX(u.second)] = 1;
            }
        }
    }
}

void do_bfs(int N) {
    for (int i = 0; i < N; i++) {
        bfs(i);
    }
}

void print_graph(int N) {
    for (int i = 0; i < N; i++) {
        printf("%d:", i + 1);
        for (auto v : G[i]) {
            printf(" %d(%c)", v.v + 1, v.company);
        }
        printf("\n");
    }
}

void print_distance_table(int N) {
    for (int i = 0; i < N; i++) {
        printf(" %4d", i + 1); 
    }
    
    printf("\n");
    
    int cont;
    for (int i = 0; i < N; i++) {
        printf("%d:  ", i + 1);
        for (int j = 0; j < N; j++) {
            cont = 0;
            for (char company = 'a'; company <= 'z'; company++) {
                if (d[i][j][COMPANY_INDEX(company)]) {
                    printf("%c", company);      
                    cont++;          
                }
            }
            for (int k = 0; k < 5 - cont; k++) {
                printf(" ");
            }
        }
        printf("\n"); 
    }
}

int main() {
    int N, u, v;
    string companies;
    bool has_at_least_one_link;
    bool first = true;
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) {
            G[i].clear();
            for (int j = 0; j < N; j++) {
                for (char company = 'a'; company <= 'z'; company++) {
                    d[i][j][COMPANY_INDEX(company)] = 0;
                }
            }
        }
            
        while (scanf("%d %d", &u, &v) == 2 && (u && v)) {
            u--; v--;
            
            cin >> companies;
            
            for (auto company : companies) {
                G[u].push_back(Node(v, company));
            }
        }
        
        #ifdef DEBUG
        print_graph(N);
        #endif
        
        do_bfs(N);
        
        #ifdef DEBUG
        print_distance_table(N);
        #endif
        
        while (scanf("%d %d", &u, &v) == 2 && (u && v)) {
            u--; v--;
            has_at_least_one_link = false;
            for (char company = 'a'; company <= 'z'; company++) {
                if (d[u][v][COMPANY_INDEX(company)]) {
                    printf("%c", company);
                    has_at_least_one_link = true;
                }
            }
            if (!has_at_least_one_link) printf("-");
            printf("\n");
        }
        
        printf("\n");
    }

    return 0;
}
