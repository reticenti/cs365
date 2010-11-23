#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class game {

    public:
        //setters and getters for all of the internal variables
        int getCredits();
        void setCredits(int);
        int getTotalCredits();
        void setTotalCredits(int);
        int getwWnnings();
        void setWinnings(int);
        int getBet();
        void setBet(int);
        int getDifficulty();
        void setDifficulty(float);
        vector<int> symbol; //holds the symbols that are to be displayed
        vector<int> color; // holds the sequence of colors 

    private:
        // We need to store all of the data for the current game.
        int credits; //holds how many credits the player has put in
        int totalCredits; //holds how many credits the player has put in so far
        int winnings; //holds how many credits the player has won so far
        unsigned short bet; //holds how many credits the player is betting this round
        float difficulty; //holds the difficulty multiplier for the simon says game

};
