#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_V 200

#define to_int(c) (c - '0')

int get_led_count (int val) {
	switch (val) {
		case 1: return 2;
		case 2: return 5;
		case 3: return 5;
		case 4: return 4;
		case 5: return 5;
		case 6: return 6;
		case 7: return 3;
		case 8: return 7;
		case 9: return 6;
	}
	return 6;
}

int main() {
	char V[MAX_V];
	int N, len, i, totalLeds;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", V);
		len = strlen(V);
		totalLeds = 0;
		for (i = 0; i < len; i++) {
			totalLeds += get_led_count (to_int (V[i]));
		}
		printf("%d leds\n", totalLeds);
	}	
	return 0;
}
