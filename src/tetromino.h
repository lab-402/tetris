#ifndef TETROMINO_H
#define TETROMINO_H
#include <iostream>

//enum ScreenInfo2{
//    screenwidth = 14,
//    screenheight = 24,
//};

const unsigned int startingpointx = 6;//(screenwidth/2 - 1);
const unsigned int startingpointy = 0;
typedef struct _pointer{
    unsigned int x;
    unsigned int y;
}pointer;

static pointer startpoint = {startingpointx, startingpointy};

enum{
    O_mino_enum = 0,
    I_mino_enum,
    S_mino_enum,
    Z_mino_enum,
    T_mino_enum,
    L_mino_enum,
    J_mino_enum,
    MAX_MINO_TYPE_enum,
};

const unsigned int MinoBlockInfo[MAX_MINO_TYPE_enum][4/*rotate*/][4/*y-axis*/][4/*x-axis*/] = {
                                                 /*O_mino*/
                                                {{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}},
                                                 /*I_mino*/
                                                {{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}},
                                                 {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}}},
                                                 /*S_mino*/
                                                {{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,0,0,0},{1,1,0,0},{0,1,0,0},{1,0,0,0}},
                                                 {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,0,0,0},{1,1,0,0},{0,1,0,0},{1,0,0,0}}},
                                                 /*Z_mino*/
                                                {{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}},
                                                 /*T_mino*/
                                                {{{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,0,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}},
                                                 /*L_mino*/
                                                {{{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
                                                 {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}}},
                                                 /*J_mino*/
                                                {{{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{0,1,0,0},{0,1,0,0},{1,1,0,0},{0,0,0,0}},
                                                 {{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}},
                                                 {{1,1,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}}},
                                                };

class Tetromino
{
private:
    pointer currentPosition;
    unsigned int minoType;
    unsigned int minoState;
public:
    Tetromino();
    ~Tetromino();
    Tetromino(unsigned int minoType): minoType(minoType),\
                                      minoState(0),\
                                      currentPosition(startpoint){};
    void Rotate();
    void Moveleft();
    void Moveright();
    void Movedown();
    pointer GetcurrentPosition();
    void GetcurrentBlockinfo(unsigned int &Type, unsigned int &State);
};

#endif // TETROMINO_H
