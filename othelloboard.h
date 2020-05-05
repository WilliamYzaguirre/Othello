#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H
#include <QGraphicsRectItem>
#include "tile.h"


class OthelloBoard
{
public:
    OthelloBoard();
    ~OthelloBoard();

    void setTile(int x, int y);


private:
    int x;
    int y;
    Tile* board[8][8];
};

#endif // OTHELLOBOARD_H

