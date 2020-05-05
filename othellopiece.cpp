#include "othellopiece.h"
#include "game.h"
#include <utility>
#include <QDebug>

extern Game *game;
OthelloPiece::OthelloPiece(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setColor("None");
}

OthelloPiece::~OthelloPiece() {
    delete this;
}

void OthelloPiece::setColor(QColor color) {
    brush.setColor(color);
    setBrush(color);
}

QString OthelloPiece::getColor()
{
    return color;
}

void OthelloPiece::flipColor()
{

}

void OthelloPiece::setLocation(std::pair<int, int> loc) {
    rowLoc = loc.first;
    colLoc = loc.second;
}
