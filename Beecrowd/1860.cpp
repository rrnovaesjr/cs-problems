#include <bits/stdc++.h>
#define PRECISION 1e-03
#define MAXN 50000

using namespace std;

int N, X;

double cordx[MAXN];

double cordy[MAXN];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double dist(double x, double y) {
	double res = 0.0;
	for(int i = 0; i < N; i++) {
		res = max(res, dist(x, y, cordx[i], cordy[i]));
	}
	return res;
}

double busca(double esq, double dir) {
	if(abs(esq - dir) < PRECISION)
		return (esq + dir)/2.0;
	
	double eesq = (2.0 * esq + dir)/3.0;
	double ddir = (esq + 2.0 * dir)/3.0;

	if(-1.0 * dist(eesq, 0.0) < -1.0 * dist(ddir, 0.0))
		return busca(eesq, dir);
	else
		return busca(esq, ddir);
}

int main() {
	scanf("%d %d", &N, &X);
	
	for(int i = 0; i < N; i++)
		scanf("%lf %lf", &cordx[i], &cordy[i]);
		
	int mincord = 0;
	double xl = busca(0.0, (double) X);
	double d = 0.0;
	for(int i = 0; i < N; i++)
		d = max(d, dist(xl, 0.0, cordx[i], cordy[i]));

	printf("%.2lf %.2lf\n", xl, d);

	return 0;
}
