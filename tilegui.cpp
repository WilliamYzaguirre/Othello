#include "tilegui.h"
#include "game.h"
#include <QDebug>
#include "diskgui.h"


//extern Game *game;
TileGui::TileGui(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    brush.setStyle(Qt::SolidPattern);
    brush.setColor("#21a323");
    setBrush(brush);
    setZValue(-1);
}

TileGui::~TileGui() {
    delete this;
}

void TileGui::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event) {
        emit tileClicked(colLoc, rowLoc);
    }
}

void TileGui::setColor(QColor color) {
    brush.setColor(color);
    setBrush(brush);
}

void TileGui::setLocation(int x, int y)
{
    colLoc = x;
    rowLoc = y;
}
