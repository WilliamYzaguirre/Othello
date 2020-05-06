#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H
#include <QGraphicsRectItem>
#include "tilegui.h"


class OthelloBoard
{
public:
    OthelloBoard(int x, int y);
    ~OthelloBoard();

    void setBlackMoves();
    void setWhiteMoves();

    std::vector<std::pair<int, int>> getBlackMoves();
    std::vector<std::pair<int, int>> getWhiteMoves();

    void setTile(TileState state, int x, int y);
    TileState getTile(int x, int y);
    void flipTile(int x, int y);


private:
    int x;
    int y;
    TileState board[8][8];

    std::vector<std::pair<int, int>> blackMoves;
    std::vector<std::pair<int, int>> whiteMoves;

};

#endif // OTHELLOBOARD_H

