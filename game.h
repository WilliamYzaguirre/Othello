#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tilegui.h"
#include "othelloboard.h"
#include <QObject>
#include "guidesign.h"
#include "gamestate.h"
#include "gameengine.h"

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

    void displayPiece(int col, int row);


signals:
    void moveMade(int, int);

public slots:
    void start();
    void updateGame();
    void tileClickedReceive(int, int);

private:
    QString turn;
    GameEngine* gameEngine;
    QGraphicsTextItem *turnDisplay;
    std::pair<int, int> boardXY;
    int turnNumber;
    GuiDesign* drawer;
    GameState* gameState;
};

#endif // GAME_H
