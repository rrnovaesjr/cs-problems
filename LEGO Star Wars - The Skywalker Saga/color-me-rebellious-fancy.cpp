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

int distance(GameState currentGame, GameState goal) {
    return abs(currentGame ^ goal);
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

struct NodeMinimum {

    GameState goal;
    
    NodeMinimum() {}
    
    NodeMinimum(GameState goal): goal(goal) {}

    bool operator ()(Node u, Node v) {
        return gamestateoperations::distance(u.gameState, goal) > gamestateoperations::distance(v.gameState, goal); 
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
        
    NodeMinimum comparator(goal);
    priority_queue<Node, vector<Node>, NodeMinimum> Q(comparator);
    
    Q.push(Node(sourceState, 0, 0));
    
    int it = 1;
    while (!Q.empty()) {
        Node u = Q.top();
        Q.pop();
        
        result.setCoordinates(u.gameState, u.positionX, u.positionY);
        
        if (u.gameState == goal) break;
        
        #ifdef DEBUG
        printf("%d,%d -> %d\n", u.positionX, u.positionY, gamestateoperations::distance(u.gameState, goal));
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
    
    auto path = result.ancestor;
    int count = 0;
    GameState u = goal;
    do {
        u = path[u];
        auto coordinates = result.coordinates[u];
        printf("%d %d\n", coordinates.first, coordinates.second); 
        gamestateoperations::printGameState(u);
        count++;
    } while (u != source);
    
    printf("%d\n", count);
    
    return 0;
}
