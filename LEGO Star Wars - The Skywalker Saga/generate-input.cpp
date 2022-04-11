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

int main() {
    GameState goal = 0b1111111111111111111111111;    
    Color goalColor;
    int jumpAmount;
    
    scanf("%d", &goalColor);
    
    if (goalColor == 0) goal = !goal;
    
    scanf("%d", &jumpAmount);

    while(jumpAmount--) {
        int randomX = rand() % GAME_SIZE;
        int randomY = rand() % GAME_SIZE;
        
        goal = gamestateoperations::jumpTo(goal, randomX, randomY);
    }
    
    gamestateoperations::printGameState(goal);
    printf("%d", goalColor);
        
    return 0;
}
