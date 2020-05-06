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

    void gameOver();
    void removeAll();

    void displayMainMenu();   

signals:
    void moveMade();

public slots:
    void start();
    void updateGame();
    void drawPiece(int col, int row); //std::pair<int, int> coordinates, std::pair<int, int> gridloc);

private:
    QGraphicsScene *gameScene;
    QString turn;
    OthelloBoard *othello;
    QList<QGraphicsItem*> listG;
    QGraphicsTextItem *turnDisplay;
    std::pair<int, int> boardXY;
    int turnNumber;
};

#endif // GAME_H
