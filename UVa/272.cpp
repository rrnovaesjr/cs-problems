#include <bits/stdc++.h>

using namespace std;

int main() {
	char ch;
	bool wait = false;
	while(ch = getchar(), ch != EOF) {
		if(ch == '\"' && !wait) {
			printf("``");
			wait = true;
		}
		else if(ch == '\"' && wait) {
			printf("''");
			wait = false;
		}
		else {
			printf("%c", ch);
		}
	}
	
	return 0;
}
