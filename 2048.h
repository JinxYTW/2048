#include <vector>
enum direction {UP, DOWN, LEFT, RIGHT};

class Game2048 {

public:

    std::vector<std::vector<int>> board;
    Game2048();
    void play();
    void printBoard();
    int score();
    bool StillEmpty(std::vector<std::pair<int, int>> emptyTiles);
    bool isWin(std::vector<std::vector<int>> board);
    void clearScreen();
    
private:
    
    void initBoard();
    void addTile();
    void movetile(direction dir);
    
};

