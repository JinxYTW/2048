#include "2048.h"
#include <iostream>

Game2048::Game2048()
{
    initBoard();
    addTile();
    addTile();
}

void Game2048::initBoard()
{
     std::vector<int> row(4, 0); // Create a row of four cells, all initialized to zero

    for (int i = 0; i < 4; i++)
    {
        board.push_back(row); // A revoir
    } 
}

void Game2048::printBoard()
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "+----+----+----+----+" << std::endl;
        for (int j = 0; j < 4; j++)
        {
            std::cout << "|";
            if (board[i][j] == 0)
            {
                std::cout << "   ";
            }
            else
            {
                std::cout << board[i][j] << "   ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "+----+----+----+----+" << std::endl;
}
//Check if the board is full
bool Game2048::StillEmpty(std::vector<std::pair<int, int>> emptyTiles)
{
    return emptyTiles.size() == 0;
}


void Game2048::addTile()
{
        // Create a list of all empty spots on the board
        //Copilot m'a proposé std::pair
    std::vector<std::pair<int, int>> emptySpots; // Equivalent de [[,],[,]....] en Python
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                emptySpots.push_back({i, j});
            }
        }
    }

    if(StillEmpty(emptySpots)==true)
    {
        std::cout << "Game Over" << std::endl;
        exit(0);
    }

        // Pick a random empty spot
    int randomIndex = rand() % emptySpots.size(); //On execute une division euclidienne de rand() par la taille de emptySpots et on récupère le reste
    std::pair<int, int> randomSpot = emptySpots[randomIndex];
    
        // Place a 2 or a 4 tile at that spot
    int randomValue = rand() % 10; // On récupère un nombre aléatoire entre 0 et 9
    if (randomValue == 0)
    {
        board[randomSpot.first][randomSpot.second] = 4;
    }
    else
    {
        board[randomSpot.first][randomSpot.second] = 2;
    }
}

void Game2048::movetile(direction dir) //Utilisation de Copilot pour celle ci
{
    if (dir == UP)
    {
        for (int j = 0; j < 4; j++)
        {
            int i = 0;
            while (i < 4)
            {
                //Test if the tile is empty
                if (board[i][j] == 0)
                {
                    i++;
                }
                //Test if the tile is not empty
                else
                {
                    //Search for the next tile
                    int k = i + 1;
                    //Test if the next tile is empty
                    while (k < 4 && board[k][j] == 0)
                    {
                        k++;
                    }
                    //Test if the tile is at the end of the board
                    if (k == 4)
                    {
                        //Change row
                        i++;
                    }
                    //Test if the next tile is different
                    else if (board[i][j] != board[k][j])
                    {
                        //Change row
                        i = k;
                    }
                    //Test if the next tile is the same
                    else
                    {
                        //Fusion
                        board[i][j] *= 2;
                        //Empty the next tile
                        board[k][j] = 0;
                        //Change row
                        i = k + 1;
                    }
                }
            }
        }
    }
    else if (dir == DOWN)
    {
        for (int j = 0; j < 4; j++)
        {
            int i = 3;
            while (i >= 0)
            {
                if (board[i][j] == 0)
                {
                    i--;
                }
                else
                {
                    int k = i - 1;
                    while (k >= 0 && board[k][j] == 0)
                    {
                        k--;
                    }
                    if (k == -1)
                    {
                        i--;
                    }
                    else if (board[i][j] != board[k][j])
                    {
                        i = k;
                    }
                    else
                    {
                        board[i][j] *= 2;
                        board[k][j] = 0;
                        i = k - 1;
                    }
                }
            }
        }
    }
    else if (dir == LEFT)
    {
        for (int i = 0; i < 4; i++)
        {
            int j = 0;
            while (j < 4)
            {
                if (board[i][j] == 0)
                {
                    j++;
                }
                else
                {
                    int k = j + 1;
                    while (k < 4 && board[i][k] == 0)
                    {
                        k++;
                    }
                    if (k == 4)
                    {
                        j++;
                    }
                    else if (board[i][j] != board[i][k])
                    {
                        j = k;
                    }
                    else
                    {
                        board[i][j] *= 2;
                        board[i][k] = 0;
                        j = k + 1;
                    }
                }
            }
        }
    }
    else if (dir == RIGHT)
    {
        for (int i = 0; i < 4; i++)
        {
            int j = 3;
            while (j >= 0)
            {
                if (board[i][j] == 0)
                {
                    j--;
                }
                else
                {
                    int k = j - 1;
                    while (k >= 0 && board[i][k] == 0)
                    {
                        k--;
                    }
                    if (k == -1)
                    {
                        j--;
                    }
                    else if (board[i][j] != board[i][k])
                    {
                        j = k;
                    }
                    else
                    {
                        board[i][j] *= 2;
                        board[i][k] = 0;
                        j = k - 1;
                    }
                }
            }
        }
    }
}

bool Game2048::isWin(std::vector<std::vector<int>> board)
{
    bool win = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j =0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                win = true;
            }
        }
    }
    return win;
}

void Game2048::play()
{
    while (true)
    {
        printBoard();
        std::cout << "Enter a move (ZQSD): ";
        char move;
        std::cin >> move;
        if (move == 'z')
        {
            movetile(UP);
        }
        else if (move == 's')
        {
            movetile(DOWN);
        }
        else if (move == 'q')
        {
            movetile(LEFT);
        }
        else if (move == 'd')
        {
            movetile(RIGHT);
        }
        else
        {
            std::cout << "Invalid move" << std::endl;
            continue;
        }
        if(isWin(board)==true)
        {
            std::cout << "You win" << std::endl;
            exit(0);
        }
        else
        {
            addTile();
        }
        
    }
}




void Game2048::score()
{
    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j =0; j < 4; j++)
        {
            score += board[i][j];
        }
    }
    std::cout << "Your score is: " << score << std::endl;
}



