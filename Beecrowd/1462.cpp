#include <bits/stdc++.h>
#define N 105000

using namespace std;

typedef long long ll;

ll d[N];

bool erdosGallai(ll n) {
  ll ocGraus[n];
  ll maiorGrau, menorGrau, somaGraus;
  
  somaGraus = maiorGrau = 0;
  menorGrau = n;
  memset(ocGraus, 0, sizeof(ll) * (n + 1));
  
  /*
   * testes inciais:
   * - nenhum grau pode ser menor que 0
   * - nenhum grau pode ser maior que n
   * - o somatório dos graus deve ser par e nunca maior que n^2/2 - n/2
   */
  for(ll i = 0; i < n; i++) {
      if(d[i] < 0 || d[i] >= n) {
	//cout << "ret 1" << endl;
	return false;
      }
      if(maiorGrau < d[i])
	maiorGrau = d[i];
      if(menorGrau > d[i])
	menorGrau = d[i];
      somaGraus += d[i];
      ocGraus[d[i]]++;
  }
  if(somaGraus % 2 || somaGraus > n * (n - 1)) {
    //cout << "ret 2" << endl;
    return false;
  }
  
  /*
   * Execução do algoritmo
   */
  if(n == 0 || 4 * menorGrau * n >= (maiorGrau + menorGrau + 1) * (maiorGrau + menorGrau + 1)) {
    //cout << "ret 3" << endl;
    return true;
  }
  ll k, somatorio, sNj, sJnj, tam;
  
  k = somatorio = sNj = sJnj = 0;
  for(int dk = maiorGrau; dk >= menorGrau; dk--) {
      if(dk < k + 1) {
	//cout << "ret 4" << endl;
	return true;
      }
      if(ocGraus[dk] > 0) {
	tam = ocGraus[dk];
	if(dk < k + tam)
	  tam = dk - k;
	somatorio += tam * dk;
	
	for(int v = 0; v < tam; v++) {
	  sNj += ocGraus[k + v];
	  sJnj += (k + v) * ocGraus[k + v];
	}
	k += tam;
	if(somatorio > k * (n - 1) - k * sNj + sJnj) {
	  //cout << "ret 5" << endl;
	  return false;
	}
      }
  }
  return true;
  
}

int main() {
    ll n;
    
    while(cin >> n) {
	for(ll i = 0; i < n; i++)
	    cin >> d[i];
	if(erdosGallai(n))
	    cout << "possivel" << endl;
	else
	    cout << "impossivel" << endl;
    }
    
    return 0;
}