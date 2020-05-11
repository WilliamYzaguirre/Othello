#include "othelloboard.h"
#include "tilegui.h"
#include "game.h"
#include "diskgui.h"
#include <utility>


OthelloBoard::OthelloBoard()
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if ((x == 3 && y == 4) || (x == 4 && y == 3)) {
                board[x][y] = black;
                //qDebug("bl");
            }
            else if ((x == 3 && y == 3) || (x == 4 && y == 4)) {
                board[x][y] = white;
                //qDebug("wh");

            }
            else {
                //qDebug("em");
                board[x][y] = empty;
            }
        }
    }
}

OthelloBoard::~OthelloBoard()
{

}
/**
void OthelloBoard::setBlackMoves()
{
    blackMoves.clear();
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            //once at a black tile, check in every direction if adjecent white piece,
            //then traverse in that direction till another typw of tile is found
            //if empty, add to vector, if not, don't
            if (board[i][j]->getState() == black) {

                //upper left: col-1, row-1
                if (board[i-1][j-1]->getState() == white) {
                    int x = i-1;
                    int y = j-1;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        x -= 1;
                        y -= 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //up: row-1
                if (board[i][j-1]->getState() == white) {
                    int x = i;
                    int y = j-1;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        y -= 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //upper right: x+1, y-1
                if (board[i+1][j-1]->getState() == white) {
                    int x = i+1;
                    int y = j-1;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        x += 1;
                        y -= 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //left: x-1, y
                if (board[i-1][j]->getState() == white) {
                    int x = i-1;
                    int y = j;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        x += 1;
                        //y -= 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //right: x+1, y
                if (board[i+1][j]->getState() == white) {
                    int x = i+1;
                    int y = j;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        x += 1;
                        //y -= 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //lower left: x-1, y+1
                if (board[i-1][j+1]->getState() == white) {
                    int x = i-1;
                    int y = j+1;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        x -= 1;
                        y += 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //down: x, y+1
                if (board[i][j+1]->getState() == white) {
                    int x = i;
                    int y = j+1;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        //x += 1;
                        y += 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //lower right: x+1, y+1
                if (board[i+1][j+1]->getState() == white) {
                    int x = i+1;
                    int y = j+1;
                    while (board[x][y]->getState() == white && x < 8 && y < 8 && x >= 0 && y >= 0) {
                        x += 1;
                        y += 1;
                    }
                    if (board[x][y]->getState() == empty) {
                        blackMoves.push_back(std::make_pair(x,y));
                    }
                }

                //TODO copy paste all these and replace them for every direction, then do the same for white
            }
        }
    }
}
**/
void OthelloBoard::setWhiteMoves()
{

}
/**
std::vector<std::pair<int, int> > OthelloBoard::getBlackMoves()
{

}

std::vector<std::pair<int, int> > OthelloBoard::getWhiteMoves()
{

}
**/
//Sets tile at x,y to state (black, white, empty)
void OthelloBoard::setTile(TileState state, int x, int y) {
    board[x][y] = state;
}

//Returns tile state (black, white, empty) at x,y
TileState OthelloBoard::getTile(int x, int y)
{
    return board[x][y];
}

//Flips tile at x,x
void OthelloBoard::flipTile(int x, int y)
{
    if (board[x][y] != empty) {
        if (board[x][y] == white) {
            board[x][y] = black;
        }
        else {
            board[x][y] = white;
        }
    }
}

bool OthelloBoard::isValidTile(int x, int y)
{
    if (x < 8 && x > -1 && y < 8 && y > -1) {
        return true;
    }
    else {
        return false;
    }
}





