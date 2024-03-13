#include <bits/stdc++.h>
#define DIST 12500

using namespace std;

int main(void) {
    int X, Y;
    
    scanf("%d %d", &X, &Y);

    printf("%.0f\n", ceil(Y/(double) (Y - X)));
    
    return 0;
}
