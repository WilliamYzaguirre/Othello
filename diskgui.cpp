#include "diskgui.h"
#include "game.h"
#include <utility>
#include <QDebug>

extern Game *game;
DiskGui::DiskGui(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setColor("None");
}

DiskGui::~DiskGui() {
    delete this;
}

void DiskGui::setColor(QColor color) {
    brush.setColor(color);
    setBrush(color);
}

void DiskGui::flipColor()
{
    if (brush.color() == Qt::white) {
        brush.setColor(Qt::black);
        setBrush(brush);
    }
    else {
        brush.setColor(Qt::white);
        setBrush(brush);
    }
}
