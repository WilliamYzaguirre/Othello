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
    mainScene = new QGraphicsScene();
    mainScene->setSceneRect(0,0,1400,900);

    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(mainScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
}

//adds object to main scene
void GuiDesign::addToScene(QGraphicsItem *item) {
    mainScene->addItem(item);
}

//removes object from main scene
void GuiDesign::removeFromScene(QGraphicsItem *item) {
    mainScene->removeItem(item);
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
        mainScene->removeItem(items);
    }
}


//signals that the start button has been clicked
void GuiDesign::sendStart() {
    emit startSignal();
}
