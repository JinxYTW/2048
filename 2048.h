#include <vector>
class Game2048 {

public:

    std::vector<std::vector<int>> board;
    Game2048();
    void play();
    void printBoard();
    void score();
    bool StillEmpty(std::vector<std::pair<int, int>> emptyTiles);
    bool isWin(std::vector<std::vector<int>> board);
    
private:
    
    void initBoard();
    void addTile();
    void movetile(direction dir);
    
};

enum direction {UP, DOWN, LEFT, RIGHT};