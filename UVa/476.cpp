#include <bits/stdc++.h>

using namespace std;

struct r {
	double x1, y1, x2, y2;
	
	bool contem(double x, double y) {
		if(x > x1 && x < x2 && y > y1 && y < y2) {
			return true;
		}
		return false;
	}
	
	r() {}
	
	r(double a, double b, double c, double d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
};

vector<r> retangulos;

int main() {
	char ch;
	int n;
	double x1, x2, y1, y2;
	
	while(cin >> ch, ch != '*') {
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2)
			swap(x1, x2);
		if(y1 > y2)
			swap(y1, y2);
		retangulos.push_back(r(x1, y1, x2, y2));
	}
	
	int p = 1;
	bool tem;
	while(cin >> x1 >> y1, x1 != 9999.9 && y2 != 9999.9) {
		tem = false;
		for(int i = 0; i < retangulos.size(); i++) {
			if(retangulos[i].contem(x1, y1)) {
				cout << "Point " << p << " is contained in figure " << i + 1 << endl;
				tem = true;
			}
		}
		if(!tem) {
			cout << "Point " << p << " is not contained in any figure" << endl;
		}
		p++;
	}

	return 0;
}
