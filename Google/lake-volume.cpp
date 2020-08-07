#include <bits/stdc++.h>

using namespace std;

int getLakesVolume(vector<int> islands) {
	int start = 0, end = islands.size() - 1;
	int i = start + 1, j = end - 1;
	while(start != end && (islands[i] <= islands[start] || islands[j] <= islands[end])) {
		if(islands[i] <= islands[start])
			i++;
		if(islands[j] <= islands[end])
			j--;
	}
	start = i, end = j;
	int maxV, result = 0;
	while(i < end) {
		j = i + 1;
		while(islands[j] < islands[i] && j < end) {
			j++;
		}
		maxV = min(islands[i], islands[j]);
		while(i != j) {
			result += max(maxV - islands[i], 0);
			i++;
		}
	}
	return result;
}

int main() {
	vector<int> input;
	int volume;
	while(cin >> volume) {
		input.push_back(volume);
	}
	cout << getLakesVolume(input) << endl;	
	input.clear();
	return 0;
}
