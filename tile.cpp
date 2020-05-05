#include "tile.h"
#include "game.h"
#include <QDebug>
#include "othellopiece.h"

//extern Game *game;
Tile::Tile(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasPiece(false);
    setPieceColor("None");
}

Tile::~Tile() {
    delete this;
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event) {
        emit tileClicked(); //std::make_pair(this->x(), this->y()), std::make_pair(colLoc, rowLoc));
    }
}

void Tile::setColor(QColor color) {
    brush.setColor(color);
    setBrush(color);
}

void Tile::placePiece() {
    qDebug("place piece");
}

bool Tile::getHasPiece() {
    return hasPiece;
}

void Tile::setHasPiece(bool b) {
    hasPiece = b;
}

QString Tile::getPieceColor() {
    return pieceColor;
}

void Tile::setPieceColor(QString value) {
    pieceColor = value;
}

/**
void Tile::setPosition(std::pair<int, int> pos)
{
    this->pos = pos;
}

std::pair<int, int> Tile::getPos()
{
    return pos;
}
**/
