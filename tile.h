#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "TileState.h"

class Tile : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    Tile(QGraphicsItem *parent = 0);
    ~Tile();


    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setColor(QColor color);
    void placePiece();

    bool getHasPiece();
    void setHasPiece(bool b);

    QString getPieceColor();
    void setPieceColor(QString value);

    //void setPosition(std::pair<int, int> pos);
    //std::pair<int, int> getPos();

    int rowLoc;
    int colLoc;

    TileState getState();
    void setState(TileState t);

signals:
    void tileClicked(int x, int y);

private:
    QBrush brush;
    bool hasPiece;
    QString pieceColor;
    std::pair<int, int> pos;
    TileState state;
};

#endif // TILE_H
