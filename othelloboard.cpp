#include "othelloboard.h"
#include "tile.h"
#include "game.h"
#include "othellopiece.h"
#include <utility>


OthelloBoard::OthelloBoard(int x, int y)
    :x{x}, y{y}
{

}

OthelloBoard::~OthelloBoard()
{

}

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

void OthelloBoard::setWhiteMoves()
{

}

std::vector<std::pair<int, int> > OthelloBoard::getBlackMoves()
{

}

std::vector<std::pair<int, int> > OthelloBoard::getWhiteMoves()
{

}

void OthelloBoard::setTile(Tile* tile, int x, int y) {
    board[x][y] = tile;
}

Tile* OthelloBoard::getTile(int x, int y)
{
    return board[x][y];
}

void OthelloBoard::flipTile(int x, int y)
{
    if (board[x][y]->getState() != empty) {
        if (board[x][y]->getState() == white) {
            board[x][y]->setState(black);
        }
        else {
            board[x][y]->setState(white);
        }
    }
}





