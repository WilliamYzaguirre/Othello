#include "game.h"
#include <QPixmap>
#include <QDebug>
#include "othelloboard.h"
#include "button.h"
#include "diskgui.h"
#include <QColor>
#include "tilegui.h"
#include <utility>

Game::Game()// : QGraphicsView(parent)
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

    turnNumber = 0;
}

void Game::begin() {
    drawer->show();
    displayMainMenu();
    connect(drawer, SIGNAL(startSignal()), this, SLOT(start()));
}

void Game::displayBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            drawer->drawTile(i , j);
        }
    }
}

QString Game::getTurn() {
    return turn;
}

void Game::setTurn(QString value) {
    turn = value;
}

void Game::changeTurn()
{
    if(getTurn() == "WHITE")
        setTurn("BLACK");
    else
        setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + getTurn());
}

void Game::start() {
    drawer->removeMainMenu();

    drawer->drawPiece(4,3, Qt::black);
    drawer->drawPiece(3,4, Qt::black);
    drawer->drawPiece(3,3, Qt::white);
    drawer->drawPiece(4,4, Qt::white);

    drawer->connectTiles();
    connect(drawer, SIGNAL(sendTileClick(int, int)), this, SLOT(displayPiece(int, int)));
    connect(this, SIGNAL(moveMade()), this, SLOT(updateGame()));

    turnNumber = 1;
}

void Game::gameOver() {

}


void Game::displayMainMenu()
{
    drawer->drawMainMenu();
    displayBoard();
}

void Game::displayPiece(int col, int row) {
    if (turnNumber % 2 == 0) {
        drawer->drawPiece(col, row, Qt::white);

    }
    else {
        drawer->drawPiece(col, row, Qt::black);
    }
    emit moveMade();
}

void Game::updateGame() {
    turnNumber++;
}

//std::vector<std::pair<int, int>> getPossibleMoves


