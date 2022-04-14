#include <bits/stdc++.h>
#define GAME_SIZE 5
#define GAME_AREA (GAME_SIZE*GAME_SIZE)
#define COLOR_INDEX(i, j) (((i)*GAME_SIZE)+(j))
#define INF 0x3f3f3f3f

using namespace std;

typedef int Color;
typedef int GameState;

namespace gamestateoperations {

inline Color getColorAtPosition(GameState gameState, int positionX, int positionY) {
    return (gameState & (1 << COLOR_INDEX(positionX, positionY))) >> COLOR_INDEX(positionX, positionY);
}

GameState insertColorAtPosition(GameState gameState, int positionX, int positionY, Color color) {
    return gameState | (color << COLOR_INDEX(positionX, positionY));
}

GameState invertColorAtPosition(GameState gameState, int positionX, int positionY) {
    Color newColor = !getColorAtPosition(gameState, positionX, positionY);
    Color currentColorMask = 1 << COLOR_INDEX(positionX, positionY);
    Color newColorMask = newColor << COLOR_INDEX(positionX, positionY);
    return (gameState & ~currentColorMask) | newColorMask;
}

void printGameState(GameState gameState) {
    for (int i = 0; i < GAME_SIZE; i++) {
        for (int j = 0; j < GAME_SIZE; j++) {
            printf("%s%d", j == 0 ? "" : " ", getColorAtPosition(gameState, i, j));
        }
        printf("\n");
    }
}

GameState jumpTo(GameState currentGame, int positionX, int positionY) {
    for (int i = -1; i <= 1; i++) {
        int pi = positionX + i;
        if (pi >= 0 && pi < GAME_SIZE) {
            for (int j = -1; j <= 1; j++) {
                int pj = positionY + j;
                if (pj >= 0 && pj < GAME_SIZE && !(positionX == pi && positionY == pj)) {
                    currentGame = invertColorAtPosition(currentGame, pi, pj);
                }
            }
        }
    }
    return currentGame;
}

}

struct Node {

    GameState gameState;
    int positionX;
    int positionY;
    
    Node() {}
    
    Node(GameState gameState, int positionX, int positionY): gameState(gameState), positionX(positionX), positionY(positionY) {}
    
    vector<Node> neighbours() {
        vector<Node> adjList;
        for (int i = 0; i < GAME_SIZE; i++) {
            for (int j = 0; j < GAME_SIZE; j++) {
                adjList.push_back(Node( gamestateoperations::jumpTo(gameState, i, j), i, j ));
            }
        }
        return adjList;
    }
};

struct Result {
    unordered_map<GameState, GameState> ancestor;
    unordered_map<GameState, pair<int, int>> coordinates;
    
    void setAncestor(GameState u, GameState v) { ancestor[u] = v; }
    
    void setCoordinates(GameState u, int positionX, int positionY) {
        coordinates[u] = make_pair(positionX, positionY);
    }
    
    bool isVisited(GameState u) {
        return ancestor.find(u) != ancestor.end();
    }
    
};

Result minimize(GameState sourceState, GameState goal) {
    Result result;
        
    queue<Node> Q;
    
    Q.push(Node(sourceState, 0, 0));
    
    int it = 1;
    while (!Q.empty()) {
        Node u = Q.front();
        Q.pop();
        
        result.setCoordinates(u.gameState, u.positionX, u.positionY);
        
        if (u.gameState == goal) break;
        
        #ifdef DEBUG
        gamestateoperations::printGameState(u.gameState);
        #endif
        
        vector<Node> neighbours = u.neighbours();
        for (Node v : neighbours) {
            if (!result.isVisited(v.gameState)) {
                Q.push(v);
                result.setAncestor(v.gameState, u.gameState);
            }
        }
    }
    return result;
}

int main() {
    GameState source = 0b0000000000000000000000000, goal = 0b1111111111111111111111111;
    Color color;
    for (int i = 0; i < GAME_SIZE; i++) {
        for (int j = 0; j < GAME_SIZE; j++) {
            scanf("%d", &color);
            source = gamestateoperations::insertColorAtPosition(source, i, j, color);
        }
    }
    
    Color goalColor;
    
    scanf("%d", &goalColor);
    
    if (goalColor == 0) goal = !goal;
    
    Result result = minimize(source, goal);
    
    auto ancestor = result.ancestor;
    int count = 0;
    GameState u = goal;
    stack<Node> path;

    do {
        auto coordinates = result.coordinates[u];
        path.push(Node(u, coordinates.first, coordinates.second));
        count++;
        u = ancestor[u];
    } while (u != source);
    
    path.push(Node(source, 0, 0));
    
    printf("%d\n", count);
    
    Node x; 
    while (!path.empty()) {
        x = path.top();
        path.pop();
        
        printf("%d %d\n", x.positionX, x.positionY);
        gamestateoperations::printGameState(x.gameState);
    }
    
    return 0;
}
