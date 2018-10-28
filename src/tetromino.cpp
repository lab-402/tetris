#include "tetromino.h"

Tetromino::Tetromino()
{

}
Tetromino::Tetromino(unsigned int minoType)
{
    std::cout << "Tetromino Create!" << std::endl;
}
Tetromino::~Tetromino()
{

}
void Tetromino::Rotate()
{
    this->minoState = (this->minoState+1)%4;
}
void Tetromino::Moveleft()
{
    this->currentPosition.x--;
}
void Tetromino::Moveright()
{
    this->currentPosition.x++;
}
void Tetromino::Movedown()
{
    this->currentPosition.y++;    
}
pointer Tetromino::GetcurrentPosition()
{
    return this->currentPosition;    
}
void Tetromino::GetcurrentBlockinfo(unsigned int &Type, unsigned int &State) {
    Type = this->minoType;
    State = this->minoState;
    return;
}