#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N;
	string leitura, sep = "";
	map<string, int> m;
	
	scanf("%d", &N);
	getchar();
	getline(cin, leitura);
	int total;
	while(N--) {
		total = 0;
		while(getline(cin, leitura) && leitura != "") {
			m[leitura]++;
			total++;
		}
		
		cout << sep;
		sep = "\n";
		for(map<string, int>::iterator i = m.begin(); i != m.end(); i++) 
			printf("%s %.4lf\n", i->first.c_str(), ((double) 100 * i->second/total));
		m.clear();
	
	}
	return 0;
}
