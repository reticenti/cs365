#include "game.h"

void calculateSequence(game* currentGame)
{
    //Randomly select 3 shapes and return it in the vector
    currentGame->symbol[0] = rand() % 128 + 1;
    currentGame->symbol[1] = rand() % 128 + 1;
    currentGame->symbol[2] = rand() % 128 + 1;

}

void calculateColors(game* currentGame)
{
    //change the length and speed of the simon says game by how difficult the jackpot is
    /* Here are the color codes
        int color = 0;
        int green = 1;
        int red = 2;
        int blue = 3;
        int yellow = 4;
    */

    int amountFlashes = 4 * currentGame->getDifficulty();
    for(int i = 0; i < amountFlashes; i++)
        currentGame->color.push_back(rand() % 4 + 1);
}
