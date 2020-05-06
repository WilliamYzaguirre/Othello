#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tilegui.h"
#include "othelloboard.h"
#include <QObject>
#include "guidesign.h"

class Game: public QObject
{
    Q_OBJECT
public:
    Game();

    void begin();

    void displayBoard();

    QString getTurn();
    void setTurn(QString value);
    void changeTurn();

    void gameOver();

    void displayMainMenu();   

signals:
    void moveMade();

public slots:
    void start();
    void updateGame();
    void displayPiece(int col, int row); //std::pair<int, int> coordinates, std::pair<int, int> gridloc);

private:
    QString turn;
    OthelloBoard *othello;
    QGraphicsTextItem *turnDisplay;
    std::pair<int, int> boardXY;
    int turnNumber;
    GuiDesign* drawer;
};

#endif // GAME_H
