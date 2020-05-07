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

    void gameOver();

    void displayMainMenu();   

public slots:
    void start();

private:
    GameEngine* gameEngine;
    QGraphicsTextItem *turnDisplay;
    GuiDesign* drawer;
};

#endif // GAME_H
