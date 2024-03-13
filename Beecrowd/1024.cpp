#include <bits/stdc++.h>
#define ASCII_SIZE 127
#define NEXT_N_ASCII_CHAR(a, n) ((a + n) % ASCII_SIZE)
#define PREV_ASCII_CHAR(a) ((a == 0) ? ASCII_SIZE :  a-1)

using namespace std;

inline bool is_half_of(string M, int i) {
	if (M.size() % 2 == 0)
		return i < M.size()/2;
	else
		return i <= M.size()/2;
}

string encrypt(string &M) {
	string result;
	string intermediary;
	
	char cyphedChar;
	for (int i = 0; i < (int) M.size(); i++) {
		// first pass
		cyphedChar = M[i];
		if (isalpha(M[i])) {
			cyphedChar = NEXT_N_ASCII_CHAR(cyphedChar, 3);	
		}
		// third pass
		if (is_half_of(M, i)) {
			cyphedChar = PREV_ASCII_CHAR(cyphedChar);
		}
		intermediary.push_back(cyphedChar);
	}

	//second pass :)
	while (!intermediary.empty()) {
		result.push_back(intermediary.back());
		intermediary.pop_back();
	}

	return result.c_str();
}


int main() {
	int N;
	string M;
	scanf("%d", &N);
	cin.ignore();
	while (N--) {
		getline(cin, M);

		printf("%s\n", encrypt(M).c_str());
		
		M.clear();
	}

	return 0;
}
