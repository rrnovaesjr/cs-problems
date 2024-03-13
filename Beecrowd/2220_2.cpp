#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(string str1, string str2, int m, int n) {
	register int cont = 0;
	for(register int i = 0; cont < m && i < n; i++)
		if(str1[cont] == str2[i])
			cont++;
	if(cont == m)
		return true;
	return false;
}

string getPoweredString(string e, int i) {
	string res = "";
	if(i == 0)
		return "";
	for(register int j = 0; j < e.size(); j++)
		for(register int k = 0; k < i; k++)
			res += e[j];
	return res;
}

int main() {
	ios::sync_with_stdio(false);

	register int T;
	string A, B, Bl;
	register int esq, dir, meio, maxi;
	bool res;
	cin >> T;
	cin >> ws;
	while(T--) {
		getline(cin, A);
		getline(cin, B);
		
		esq = 0;
		if(B.size() > 0)
			dir = A.size()/B.size() + 1;
		else
			dir = A.size() + 1;

		if( !isSubSequence(B, A, B.size(), A.size()) ) {
			cout << "0" << endl;
			continue;
		}
		maxi = 0;
		while(!(dir == esq + 1)) {
			meio = (esq + dir)/2;
			Bl = getPoweredString(B, meio);

			if(isSubSequence(Bl, A, Bl.size(), A.size())) {
				maxi = max(maxi, meio); 
				esq = meio;
			}
			else
				dir = meio;
		}
		cout << maxi << endl;
	}

	return 0;
}
