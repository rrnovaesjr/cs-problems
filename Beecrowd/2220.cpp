#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(string str1, string str2, int m, int n, int i) {
	register int cont = 0;
	for(register int j = 0; cont < m * i && j < n; j++)
		if(str1[ cont / i] == str2[j])
			cont++;
	if(cont == m * i)
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);

	register int T;
	string A, B, Bl;
	register int esq, dir, meio, maxi;
	bool res;
	cin >> T;
	while(T--) {
		cin >> A;
		cin >> B;
		
		esq = 0;
		dir = A.size()/B.size() + 1;

		if( !isSubSequence(B, A, B.size(), A.size(), 1) ) {
			cout << "0" << endl;
			continue;
		}
		maxi = 0;
		while(!(dir == esq + 1)) {
			meio = (esq + dir)/2;
			if( isSubSequence(B, A, B.size(), A.size(), meio) ) {
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
