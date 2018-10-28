#include <QtWidgets>

#include "gamemanager.h"

/*for array calculation*/
const unsigned int screenleftend = 1;
const unsigned int screenrightend = screenwidth -2;
const unsigned int screentopend = 2;
const unsigned int screendownend = screenheight -2;
const unsigned int scorearray[5] = {0,100,300,1000,2000};

GameManager::GameManager()
{
    for(unsigned int i = 0;i < screenwidth; i ++)
    {
        for(unsigned int j = 0; j < screenheight; j++)
        {
            if(i < screenleftend || i > screenrightend)
            {
                screenInfo[screenwidth][screenheight] = 1;                                                
            }
        }
    }
}
void GameManager::SetNextLevel()
{
    this->gamelevel++;
    // this->gravity++;
}

unsigned int GameManager::GetNextMino()
{
    srand((unsigned int)time(0));
    return rand()%7;
}

unsigned int GameManager::GetLevel()
{
    return this->gamelevel;
}

unsigned int GameManager::GetScore()
{
    return this->score;
}

void GameManager::MinoDefrag()
{
    unsigned int fulllinecounter = 0;
    for(unsigned int checkline = screendownend;checkline > screentopend; checkline --)
    {
        /*flag = check line is full*/
        unsigned int flag;
        /*add 1 to flag, if there is block in sector(One)*/
        for(unsigned int checkOne =  screenleftend; checkOne < screenrightend; checkOne++)
        {
            if(screenInfo[checkOne][checkline] == 1)
            {
                flag++;
            }
        }
        /*if flag is full*/
        if(flag == (screenrightend - screenleftend +1))
        {
            /*lower uppder full layer*/
            for(unsigned int i = checkline;i > screentopend; i-- )
            {
                for(unsigned int j = screenleftend; j < screenrightend; j++)
                {
                    screenInfo[j][i] = screenInfo[j][i+1];
                }
            }
            /*and re check that line*/
            checkline--;
        }
        /*if line is empy no need to check upper layer*/
        if(flag == 0)
        {
            break;
        }
    }
    this->score += scorearray[fulllinecounter];
    this->clearedLine += fulllinecounter;
}
void GameManager::GetKeyPress() {
    return;
}
bool GameManager::ValidateMinoMove(unsigned int Move, unsigned int minoType, unsigned int minoState)
{  /* Valid : return true,   Invalid : return false */
    pointer NewPos = this->currentMino.GetcurrentPosition();
    switch (Move) {
        case Qt::Key_Left:
            NewPos.x--;
            break;
        case Qt::Key_Right:
            NewPos.x++;
            break;
        case Qt::Key_Down:
            NewPos.y++;
            break;
    }

    for(unsigned int y=0; y<4; y++) {
        for (unsigned int x=0; x<4; x++) {
            if(MinoBlockInfo[minoType][minoSate][y][x]) {
                if(this->screenInfo[NewPos.y+y][[NewPos.y+yx][NewPos.y+x])
            }
        }
    }
    return true;
}
