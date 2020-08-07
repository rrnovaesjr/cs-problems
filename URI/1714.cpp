#include <bits/stdc++.h>
#define MAXN 150
#define MAXL 128
 
using namespace std;
 
char G[MAXN][MAXN];

/* -----------------------------------------
* Redefinições dos tipos
------------------------------------------ */

typedef pair<int, int> pii;
 
typedef pair<pii, vector<int> > piC;
 
int N;
 
int isUpper(char a) {
    if(a >= 'A' && a <= 'Z')
        return 1;
    return 0;
}

/* -----------------------------------------
* Obtém os vizinhos de uma coordenada i, j.
* Não se importa se um ponto é válido, ou
* não.
------------------------------------------ */

vector<pii> obtemP(pii coord) {
    int i = coord.first, j = coord.second;
    char cam = G[i][j];
    char vizinho;
     
    int flagI = 0, flagJ = 0;
 
    if(j == 0)
        flagJ = -1;
    else if(j == N - 1)
        flagJ = 1;
     
    if(i == 0)
        flagI = -1;
    else if(i == N - 1)
        flagI = 1;  
 
    vector<pii> r;
     
    if(flagJ != -1) {
        vizinho = G[i][j - 1];
        r.push_back( make_pair( i, j - 1) );
    }
     
    if(flagJ != 1) {
        vizinho = G[i][j + 1];
        r.push_back( make_pair( i, j + 1) );
    }
     
    if(flagI != -1) {
        vizinho = G[i - 1][j];
        r.push_back( make_pair( i - 1, j) );
    }
 
    if(flagI != 1) {
        vizinho = G[i + 1][j];
        r.push_back( make_pair( i + 1, j) );
    }
     
    return r;
}

/* -----------------------------------------
* Mapa que armazena a distância até uma 
* coordenada utilizando um mapa. Considera-
* se, também, o caminho percorrido até
* este ponto.
------------------------------------------ */

pii destino;
 
map< piC, int> dist;

/* -----------------------------------------
* Busca em largura com múltiplos estados:
* deve-se considerar o caminho percorrido,
* acessando também os elementos que foram
* visitados na rota
------------------------------------------ */

int bfs() {
    //Par de origem e destino
    //fila de coordenadas a se visitar
    //até aqui, tudo igual a uma busca em
    //largura muito simples!
    pii origem = make_pair(0, 0);
    destino = make_pair(N - 1, N - 1);
    queue<piC> Q;

    //Vector de elementos visitados. Criado
    //com o tamanho de elementos da tabela ASCII.
    vector<int> cam(MAXL, 0);
    cam[G[origem.first][origem.second]] = 1;
    dist[ make_pair(origem, cam) ] = 1;
    Q.push( make_pair(origem, cam ) );

    //Pares de coordenadas u e v
    //u é aquele que será analisado num dado
    //instante, v armazenará os possíveis vizinhos
    //de u. A vizinhança é armazenada no vector
    //ladj, enquanto o vector newCam armazena
    //o novo caminho formado a partir do
    //vizinho v (se for consistente)
    pii u, v;
    vector<pii> ladj;
    vector<int> newCam;

    //Início do laço principal da busca (nenhuma novidade)
    //Enquanto houver alguém para ser visitado, continue
    while(Q.size() >= 1) {
        //Pega a primeira coordenada da fila
        //e o caminho percorrido até ela
        u = Q.front().first;
        cam = Q.front().second;
        Q.pop();

        //Se for o ponto de destino
        //então já cheguei com custo ótimo.
        //Pode parar a busca
        //Caso contrário, obtenha os vizinhos
        //da coordenada u.
        if(u == destino)
            return dist[ make_pair(u, cam) ]; 
        ladj = obtemP(u);
        
        //Percorra os vizinhos da coordenada u
        //e armazene-os em v
        for(int i = 0; i < ladj.size(); i++) {
            v = ladj[i];
         
            if(dist.count(make_pair(v, cam)))
                continue;
         
             //Se o caminho for inconsistente com a letra
            //do destino, eu não o visito!    
            if( tolower(G[v.first][v.second]) == tolower(G[destino.first][destino.second]))
                if( !isUpper(G[v.first][v.second]) && isUpper(G[destino.first][destino.second]))
                    continue;
                else if( isUpper(G[v.first][v.second]) && !isUpper(G[destino.first][destino.second]))
                    continue;

            //Se a letra da minha adjacência atual já
            //tiver ocorrido em forma capitalizada
            //diferente no caminho que computei até agora,
            //então irei formar um caminho inconsistente.
            //Não devo computar este vizinho! 
            if( !isUpper(G[v.first][v.second]) && cam[toupper(G[v.first][v.second])]) {
                continue;       
            } 
            if( isUpper(G[v.first][v.second]) && cam[tolower(G[v.first][v.second])]) {
                continue;       
            }

            //O novo caminho formado deve ser computado
            //e inserido na minha fila de visitas
            //A distância para a coordenada v é atualizada.
            //Faz-se isso se, e somente se, o meu vértice
            //não foi visitado            
            newCam = cam;
            newCam[G[v.first][v.second]] = 1;
            dist[ make_pair(v, newCam) ] = dist[ make_pair(u, cam) ] + 1;
            Q.push( make_pair(v, newCam) );
        }
    }
    //Não consegui chegar no destino
    //Retorne -1
    return -1;
}

int main() {
 
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> G[i][j];
             
    printf("%d\n", bfs());
 
    return 0;
}

