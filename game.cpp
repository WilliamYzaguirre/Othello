#include "game.h"
#include <QPixmap>
#include <QDebug>
#include "othelloboard.h"
#include "button.h"
#include "othellopiece.h"
#include <QColor>
#include "tile.h"
#include <utility>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    othello = new OthelloBoard(boardXY.first, boardXY.second);
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900);
    boardXY = std::make_pair(width()/2-20, 50);

    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);

    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100, 10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");

    turnNumber = 0;
}

void Game::drawBoard() {
    //othello = new OthelloBoard();
    //othello->drawTiles(width()/2-400,50);
    int x = width()/2-400;
    int y = 50;
    int shift = 100;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Tile* tile = new Tile();
            othello->setTile(tile, i, j);
            othello->getTile(i,j)->setState(empty);
            //this->board[i][j] = tile;
            tile->rowLoc = i;
            tile->colLoc = j;
            tile->setPos(x+shift*j, y+shift*i);
            tile->setColor("#21a323");
            //std::pair<int, int> coor = std::make_pair(x+shift*j, y+shift*i);
            //std::pair<int, int> grid = std::make_pair(j, i);
            //connect(tile,SIGNAL(tileClicked()) , this , SLOT(drawPiece(coor, grid)));
            this->addToScene(tile);
        }
    }
}

void Game::addToScene(QGraphicsItem *item) {
    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item) {
    gameScene->removeItem(item);
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
    for (QGraphicsItem* item : listG) {
        removeFromScene(item);
    }
    //othello->setStart();
    int shift = 100;
    int x = width()/2-400;
    int y = 50;
    OthelloPiece* piece = new OthelloPiece;
    othello->getTile(3,3)->setState(black);
    //this->board[3][3]->setHasPiece(true);
    piece->setPos(x+shift*3, y+shift*3);
    piece->setColor(Qt::black);
    piece->setLocation(std::make_pair(3,3));
    this->addToScene(piece);

    OthelloPiece* piece1 = new OthelloPiece;
    othello->getTile(4,3)->setState(white);
    //this->board[4][3]->setHasPiece(true);
    piece1->setPos(x+shift*4, y+shift*3);
    piece1->setColor(Qt::white);
    piece1->setLocation(std::make_pair(4,3));
    this->addToScene(piece1);

    OthelloPiece* piece2 = new OthelloPiece;
    othello->getTile(3,4)->setState(white);
    //this->board[3][4]->setHasPiece(true);
    piece2->setPos(x+shift*3, y+shift*4);
    piece2->setColor(Qt::white);
    piece2->setLocation(std::make_pair(3,4));
    this->addToScene(piece2);

    OthelloPiece* piece3 = new OthelloPiece;
    othello->getTile(4,4)->setState(black);
    //this->board[4][4]->setHasPiece(true);
    piece3->setPos(x+shift*4, y+shift*4);
    piece3->setColor(Qt::black);
    piece3->setLocation(std::make_pair(4,4));
    this->addToScene(piece3);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            connect(othello->getTile(i,j),SIGNAL(tileClicked(int, int)) , this , SLOT(drawPiece(int, int)));
        }
    }

    turnNumber = 1;
    connect(this, SIGNAL(moveMade()), this, SLOT(updateGame()));
}

void Game::gameOver() {

}

void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        if(itemsList[i]!=check)
          removeFromScene(itemsList[i]);
    }
}

void Game::displayMainMenu()
{
    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Othello");
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);
    //create Button
    Button * playButton = new Button("Play 1 v 1");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 300;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    addToScene(playButton);
    listG.append(playButton);

    //Create Quit Button
    Button * quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 375;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
    listG.append(quitButton);

    drawBoard();
}

void Game::drawPiece(int col, int row) {
    OthelloPiece* piece = new OthelloPiece;
    othello->getTile(col, row)->setState(black);
    //this->board[col][row]->setHasPiece(true);
    piece->setPos(boardXY.first+100*col, boardXY.second+100*row);
    if (turnNumber % 2 == 0) {
        piece->setColor(Qt::white);

    }
    else {
        piece->setColor(Qt::black);
    }
    piece->setLocation(std::make_pair(col, row));
    this->addToScene(piece);
    emit moveMade();
}

void Game::updateGame() {
    turnNumber++;
}

//std::vector<std::pair<int, int>> getPossibleMoves


