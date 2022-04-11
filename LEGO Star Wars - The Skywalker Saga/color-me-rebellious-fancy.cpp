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
            printf(" %d", getColorAtPosition(gameState, i, j));
        }
        printf("\n");
    }
}

int distance(GameState currentGame, GameState goal) {
    return abs(currentGame - goal);
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

    unordered_map<GameState, int> hopsCount;
    
    GameState goal;
    
    NodeMinimum() {}
    
    NodeMinimum(unordered_map<GameState, int> hopsCount, GameState goal): hopsCount(hopsCount), goal(goal) {}

    bool operator ()(Node u, Node v) {
        return hopsCount[u.gameState] + gamestateoperations::distance(u.gameState, goal) > 
            hopsCount[v.gameState] + gamestateoperations::distance(v.gameState, goal); 
    };
    
    void updateHopsCount(unordered_map<GameState, int> hopsCount) { this->hopsCount = hopsCount; }

};

struct Score {

    unordered_map<GameState, int> hopsCount;
    
    Score() {}
    
    Score(unordered_map<GameState, int> hopsCount): hopsCount(hopsCount) {}
    
    int operator()(Node u) {
        if (hopsCount.find(u.gameState) == hopsCount.end())
            return INF;
        return hopsCount[u.gameState];
    }
    
    void updateHopsCount(unordered_map<GameState, int> hopsCount) { this->hopsCount = hopsCount; }

};

queue<Node> minimize(GameState sourceState, GameState goal) {
    queue<Node> path;
    unordered_map<GameState, int> distances;
    
    distances[sourceState] = 0;
    
    NodeMinimum comparator(distances, goal);
    Score score(distances);
    priority_queue<Node, vector<Node>, NodeMinimum> Q(comparator);
    
    Q.push(Node(sourceState, 0, 0));
    
    int it = 1;
    while (!Q.empty()) {
        Node u = Q.top();
        Q.pop();
        
        path.push(u);
        
        if (u.gameState == goal) break;
        
        vector<Node> neighbours = u.neighbours();
        for (Node v : neighbours) {
            int newDistance = score(u) + 1;
            if (newDistance < score(v)) {
                
                Q.push(v);
                distances[v.gameState] = score(u) + 1;
                comparator.updateHopsCount(distances);
                score.updateHopsCount(distances);
            }
        }
    }
    return path;
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
    
    queue<Node> path = minimize(source, goal);
    
    printf("%lu\n", path.size());
    while (!path.empty()) {
        Node u = path.front();
        printf("%d %d\n", u.positionX, u.positionY);
        gamestateoperations::printGameState(u.gameState);
        path.pop();
    }
    
    return 0;
}
