#ifndef GUIDESIGN_H
#define GUIDESIGN_H
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include <diskgui.h>
#include <tilegui.h>
#include "othelloboard.h"


class GuiDesign : public QGraphicsView
{
    Q_OBJECT
public:
    GuiDesign(QWidget *parent = 0);
    ~GuiDesign();

    //GuiDesign& operator=(GuiDesign g);

    void drawMainScene();

    void drawTile(int x, int y);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    void drawMainMenu();

    void removeMainMenu();

    void drawPiece(int x, int y, QColor color);

    void connectAllTiles();

    void connectTiles(std::vector<std::pair<int, int>> tiles);

    void disconnectAllTiles();

    void disconnectTile(std::vector<std::pair<int, int>> tiles);

    void flipDisks(std::vector<std::pair<int,int>> disks);

    void reDrawPieces(OthelloBoard* board);

public slots:
    void sendStart();

signals:
    void startSignal();

private:
    QGraphicsScene* mainScene;
    QList<QGraphicsItem*> listG;

    DiskGui* diskList[8][8];
    TileGui* tileList[8][8];
};

#endif // GUIDESIGN_H
