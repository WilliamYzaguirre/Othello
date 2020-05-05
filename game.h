#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tile.h"
#include "othelloboard.h"
#include <QObject>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);

    void drawBoard();

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    QString getTurn();
    void setTurn(QString value);
    void changeTurn();

    Tile *board[8][8];
    QGraphicsTextItem *check;
    //QList<Piece> allPiece

    void gameOver();
    void removeAll();

    void displayMainMenu();

public slots:
    void start();
    void drawPiece(); //std::pair<int, int> coordinates, std::pair<int, int> gridloc);

private:
    QGraphicsScene *gameScene;
    QString turn;
    //OthelloBoard *othello;
    QList<QGraphicsItem*> listG;
    QGraphicsTextItem *turnDisplay;
};

#endif // GAME_H
