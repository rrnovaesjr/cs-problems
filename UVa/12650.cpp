#include <bits/stdc++.h>
#define MAXN 10001

using namespace std;

int voltou[MAXN];

vector<int> l;

int main() {

    int n, r, x;

    while(scanf("%d %d", &n, &r) == 2) {
        memset(voltou, 0, sizeof voltou);

        for(int i = 0; i < r; i++) {
            scanf("%d", &x);
            voltou[x] = 1;
        }
        for(int i = 1; i <= n; i++)
            if(!voltou[i])
                l.push_back(i);
        if(l.size() > 0) {
            for(int i = 0; i < l.size(); i++)
                printf("%d ", l[i]);
            printf("\n");
        }
        else
            printf("*\n");
        l.clear();
    }

    return 0;
}
