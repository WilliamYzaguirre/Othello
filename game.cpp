#include "game.h"
#include <QPixmap>
#include <QDebug>
#include "othelloboard.h"
#include "button.h"
#include "diskgui.h"
#include <QColor>
#include "tilegui.h"
#include <utility>
#include <gamestate.h>

//Master class of Othello game. Game calls GUI Design, which shows the main menu in it's constructor
//main.cpp then calls begin which sets up the main menu for the game

Game::Game()
{  

    /**
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100, 10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");
    **/

    drawer = new GuiDesign();
    drawer->drawMainScene();
}

//Sets up main menu and begins app
void Game::begin() {
    drawer->show();
    displayMainMenu();
    connect(drawer, SIGNAL(startSignal()), this, SLOT(start()));
}

//Calls GUI Design to draw all the tiles for the board
void Game::displayBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            drawer->drawTile(i , j);
        }
    }
}

//Starts a game of Othello. First, removes the menu overlay, then calls
//GUI Design to draw the starting pieces, then connects the tiles so
//they have action when clicked, and sets the turn counter to one
void Game::start() {
    drawer->removeMainMenu();
    gameEngine = new GameEngine();
}

//no more moves can be played
void Game::gameOver() {

}

//Calls GUI Design to draw the main menu (start/end buttons)
void Game::displayMainMenu()
{
    drawer->drawMainMenu();
    displayBoard();
}
