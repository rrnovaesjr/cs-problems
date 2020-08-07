#include <bits/stdc++.h>

using namespace std;

string reversa(string a) {
	string r;
	for(int i = a.size() - 1; i >= 0; i--)
		r.push_back(a[i]);
	return r;
}

int obtemch(char ch) {
	return ch - '0';
}

int main(void) {
	string opa, opb, a, b;
	int cIn, cOut, nC;
	while(cin >> opa >> opb && (atoi(opa.c_str()) || atoi(opb.c_str()))) {
		if(opa.size() > opb.size()) {
			a = reversa(opa);
			b = reversa(opb);
		}
		else {
			a = reversa(opb);
			b = reversa(opa);
		}
		
		for(int i = b.size(); i < a.size(); i++)
			b.push_back('0');
		
		nC = 0;
		cOut = 0;
		for(int i = 0; i < a.size(); i++) {
			cIn = cOut;
			cOut = 0;
			if(obtemch(a[i]) + obtemch(b[i]) + cIn >= 10) {
				nC++;
				cOut = 1;
			}
		}
		
		if(nC > 1)
			cout << nC << " carry operations." << endl;
		else if(nC == 1)
			cout << nC << " carry operation." << endl;
		else
			cout << "No carry operation." << endl;
	}
	return 0;
}
