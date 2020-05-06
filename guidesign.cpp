#include "guidesign.h"
#include <QBrush>
#include <button.h>
#include <tilegui.h>
#include <diskgui.h>

GuiDesign::GuiDesign(QWidget *parent) : QGraphicsView(parent)
{

}

GuiDesign::~GuiDesign()
{
    //TODO: go through and delete lists
}

//Draws main scene. Background rectangle of fixed size
//Width=1400, height=900
void GuiDesign::drawMainScene()
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900);

    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
}


//draws a tile for the board
void GuiDesign::drawTile(int x, int y)
{
    TileGui* tile = new TileGui();
    tile->setLocation(x, y);
    tile->setRect((1400/2-400)+100*x, 50+100*y,100,100);
    tileList[x][y] = tile;
    this->addToScene(tile);
}

//adds object to main scene
void GuiDesign::addToScene(QGraphicsItem *item) {
    gameScene->addItem(item);
}

//removes object from main scene
void GuiDesign::removeFromScene(QGraphicsItem *item) {
    gameScene->removeItem(item);
}

//draws the main menu. 2 buttons, start and quit. Start emits a signal
//that initiallizes a new ga,e in game.cpp. End quits the application
void GuiDesign::drawMainMenu()
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
    connect(playButton, SIGNAL(clicked()), this, SLOT(sendStart()));
    this->addToScene(playButton);
    listG.append(playButton);

    //Create Quit Button
    Button * quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 375;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    this->addToScene(quitButton);
    listG.append(quitButton);
}

//removes main menu from scene
void GuiDesign::removeMainMenu()
{
    for (QGraphicsItem* items : listG) {
        gameScene->removeItem(items);
    }
}

//int x: column of disk
//int y: row of disk
//QColor color: color of disk initially
//Draws a disk to the given location
void GuiDesign::drawPiece(int x, int y, QColor color)
{
    DiskGui* disk = new DiskGui();
    disk->setRect((1400/2-400)+100*x, 50+100*y,100,100);
    disk->setColor(color);
    this->addToScene(disk);
}

//Connects tiles to game.cpp so when they are clicked, the game can know
void GuiDesign::connectTiles()
{
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            connect(tileList[x][y], SIGNAL(tileClicked(int, int)), this, SLOT(recieveTileClick(int, int)));
        }
    }
}

//Signals that a tile has been clicked at x,y
void GuiDesign::recieveTileClick(int x, int y)
{
    emit sendTileClick(x, y);
}

//signals that the start button has been clicked
void GuiDesign::sendStart() {
    emit startSignal();
}
