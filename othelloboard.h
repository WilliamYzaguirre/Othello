#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H
#include <QGraphicsRectItem>
#include "tile.h"


class OthelloBoard
{
public:
    OthelloBoard(int x, int y);
    ~OthelloBoard();

    void setTile(int x, int y);

    std::pair<int, int> getXY();

    void setBlackMoves();
    void setWhiteMoves();

    std::vector<std::pair<int, int>> getBlackMoves();
    std::vector<std::pair<int, int>> getWhiteMoves();

    void setTile(Tile* tile, int x, int y);
    Tile* getTile(int x, int y);
    void flipTile(int x, int y);


private:
    int x;
    int y;
    Tile* board[8][8];

    std::vector<std::pair<int, int>> blackMoves;
    std::vector<std::pair<int, int>> whiteMoves;

};

#endif // OTHELLOBOARD_H

