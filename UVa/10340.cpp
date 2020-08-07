#include <bits/stdc++.h>
#define ASCII 256

using namespace std;


int main(void) {
	string s, t;
	int mapa[ASCII];
	queue<int> locais;
	bool flag;
	while(cin >> s >> t) {
		memset(mapa, 0, sizeof(mapa));
		flag = true;
		for(int i = 0; i < s.size(); i++) {
			mapa[s[i]] = 1;
			locais.push(s[i]);
		}
		
		
		
		for(int i = 0; i < t.size(); i++) {
			if(mapa[t[i]] == 1) {
				if(t[i] == locais.front()) {
					locais.pop();
				}
			}
		}
		
		if(locais.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		
		while(!locais.empty())
			locais.pop();
	}

	return 0;
}
