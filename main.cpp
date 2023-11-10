#include "2048.h"
#include <iostream>
#include <ctime>  // Include the ctime library
#include <cstdlib>  // Include the cstdlib library

/**
 * The main function initializes a Game2048 object and calls its play method.
 *
 * @return 0 indicating successful program termination.
 */
int main()
{
     srand(time(0));  // Seed the random number generator with the current time
     
    Game2048 game;
    game.play();
    return 0;
}
