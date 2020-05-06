#ifndef GUIDESIGN_H
#define GUIDESIGN_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include <diskgui.h>
#include <tilegui.h>


class GuiDesign : public QGraphicsView
{
    Q_OBJECT
public:
    GuiDesign(QWidget *parent = 0);
    ~GuiDesign();

    void drawMainScene();

    void drawTile(int x, int y);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    void drawMainMenu();

    void removeMainMenu();

    void drawPiece(int x, int y, QColor color);

    void connectTiles();

public slots:
    void recieveTileClick(int, int);
    void sendStart();

signals:
    void sendTileClick(int, int);
    void startSignal();

private:
    QGraphicsScene* gameScene;
    QList<QGraphicsItem*> listG;

    DiskGui* diskList[8][8];
    TileGui* tileList[8][8];
};

#endif // GUIDESIGN_H
