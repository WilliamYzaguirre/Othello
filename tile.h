#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

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

signals:
    void tileClicked(); //std::pair<int, int> coor, std::pair<int, int> grid);

private:
    QBrush brush;
    bool hasPiece;
    QString pieceColor;
    std::pair<int, int> pos;
};

#endif // TILE_H
