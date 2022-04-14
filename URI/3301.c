#include <stdio.h>

int main() {
    int H, Z, L;
    scanf("%d %d %d", &H, &Z, &L);
    int hz = H - Z;
    int zl = Z - L;
    int hl = H - L;
    
    
    if (hz * zl > 0)
        printf("zezinho\n");
    else if (hz * hl > 0)
        printf("luisinho\n");
    else
        printf("huguinho\n");

    return 0;
}
