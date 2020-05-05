#ifndef OTHELLOPIECE_H
#define OTHELLOPIECE_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include "tile.h"

class OthelloPiece : public QGraphicsRectItem
{

public:
    OthelloPiece(QGraphicsItem* parent = 0);
    ~OthelloPiece();

    void setColor(QColor color);

    void setLocation(std::pair<int, int> loc);

    QString getColor();
    void flipColor();

private:
    QBrush brush;
    QString color;
    int rowLoc;
    int colLoc;
};

#endif // OTHELLOPIECE_H
