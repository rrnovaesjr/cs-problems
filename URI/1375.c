#include <stdio.h>
#define MAXN 10010
 
int main() {
    int grid[MAXN];
    int pos[MAXN];
    int N, i, j, k, aux, foi;
 
    while(scanf("%d", &N), N) {
        foi = 1;
         
        for(i = 1; i <= N; i++) {
            scanf("%d", &grid[i]);
            scanf("%d", &pos[grid[i]]);
	    pos[grid[i]] += i;
        }
            
        i = 1;
        while(i <= N) {
            if(pos[grid[i]] == i) {
                i++;
                continue;
            }
 
            if(pos[grid[i]] > N || pos[grid[i]] <= 0) {
                foi = 0;
                break;
            }
 
	 	    j = pos[grid[i]];

			if(pos[grid[i]] == pos[grid[j]]) {
				foi = 0;
				break;
			}
				 	                 
            aux = grid[i];
            grid[i] = grid[j];
            grid[j] = aux;
        }
         
        if(!foi)
            printf("-1");
        else {
            printf("%d", grid[1]);
            for(i = 2; i <= N; i++)
                printf(" %d", grid[i]);
        }
        printf("\n");
    }
     
 
    return 0;
}
