#include <stdio.h>
#include <stdlib.h>

long long fib(int n, int *cont) {
    *cont += 1;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n - 1, cont) + fib(n - 2, cont);

}

int main() {
    int n, x, cont;
    long long ret;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        cont = 0;
        ret = fib(x, &cont);
        printf("fib(%d) = %d calls = %lld\n", x, cont - 1, ret);
    }
    return 0;
}
