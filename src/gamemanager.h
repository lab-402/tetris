#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "tetromino.h"
#include <ctime>

enum ScreenInfo{
    screenwidth = 14,
    screenheight = 24,
};

class GameManager
{
private:
    unsigned int score;
    unsigned int screenInfo[screenwidth][screenheight];
    unsigned int gravity;
    unsigned int clearedLine;
    unsigned int gamelevel;
    Tetromino currentMino;
    unsigned nextMino;
public:
    GameManager(): score(0),screenInfo({{0,},}),gravity(0),clearedLine(0),gamelevel(0),nextMino(rand()%7),\
        currentMino((static_cast<unsigned int>(rand()%7))){};
    ~GameManager();
    void SetNextLevel();
    unsigned int GetScore();
    void GetGameScreen(unsigned int* screen[screenheight]);
    unsigned int GetNextMino();
    unsigned int GetLevel();
    void MinoDefrag();
    void GetKeyPress();
    bool ValidateMinoMove(unsigned int move, unsigned int minoType, unsigned int minoState); /* Valid : return true,   Invalid : return false */
    bool GetEndMino();
};

#endif // GAMEMANAGER_H
