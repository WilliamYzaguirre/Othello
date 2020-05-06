#ifndef TILEGUI_H
#define TILEGUI_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include "TileState.h"

class TileGui : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    TileGui(QGraphicsItem *parent = 0);
    ~TileGui();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setColor(QColor color);

    void setLocation(int x, int y);

signals:
    void tileClicked(int, int);

private:
    QBrush brush;
    int rowLoc;
    int colLoc;
};

#endif // TILE_H
