#include "gameengine.h"
#include <QtDebug>
#include "othelloboard.h"
#include <iostream>
#include <string>
GameEngine::GameEngine()
{
    //gui = new GuiDesign();
    //gameState = new GameState();
    gameOverTest = false;
    gameOver = false;
    boardGui = new BoardGui();
    boardGui->drawMainScene();
    boardGui->show();
    this->run();
}

void GameEngine::run() {
    boardGui->drawBoard();
    boardGui->drawTurnIndicator();
    boardGui->drawScores();

    connect(boardGui, SIGNAL(sendTileClick(int, int)), this, SLOT(receiveTileClick(int, int)));
    //gameState->connectGameEngine(this);

    gameBoard = new OthelloBoard();


    turnCount = 1;

    boardGui->drawPiece(4,3, Qt::black);
    gameBoard->setTile(black, 4,3);

    boardGui->drawPiece(3,4, Qt::black);
    gameBoard->setTile(black, 3,4);

    boardGui->drawPiece(3,3, Qt::white);
    gameBoard->setTile(white, 3,3);

    boardGui->drawPiece(4,4, Qt::white);
    gameBoard->setTile(white, 4,4);

    doBlackTurn();
}

void GameEngine::doWhiteTurn()
{
    validMoves = getValidMoves();
    if (validMoves.size() > 0) {
        gameOverTest = false;
        boardGui->connectTiles(validMoves);
    }
    else {
        if (gameOverTest == true) {
            gameOver = true;
            endGame();
        }
        else {
            gameOverTest = true;
            doBlackTurn();
        }
    }
}

void GameEngine::doBlackTurn()
{
    validMoves = getValidMoves();
    if (validMoves.size() > 0) {
        gameOverTest = false;
        boardGui->connectTiles(validMoves);
    }
    else {
        if (gameOverTest == true) {
            gameOver = true;
            endGame();
        }
        else {
            gameOverTest = true;
            doWhiteTurn();
        }
    }
}

//const OthelloBoard& GameEngine::board() const noexcept
//{
//    //const OthelloBoard retBoard = *gameBoard;
//    //return retBoard;
//}

int GameEngine::getBlackScore() const noexcept
{
    int total = 0;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (gameBoard->getTile(x,y) == black) {
                total++;
            }
        }
    }
    return total;
}

int GameEngine::getWhiteScore() const noexcept
{
    int total = 0;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (gameBoard->getTile(x,y) == white) {
                total++;
            }
        }
    }
    return total;
}

void GameEngine::endGame() noexcept
{
    if (getBlackScore() > getWhiteScore()) {
        boardGui->drawEndGame(black);
    }
    else {
        boardGui->drawEndGame(white);
    }
}

bool GameEngine::isBlackTurn() const noexcept
{
    if (turnCount % 2 == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool GameEngine::isWhiteTurn() const noexcept
{
    if (turnCount % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool GameEngine::isValidMove(int x, int y) const noexcept
{
    if (isWhiteTurn()) {
        if (gameBoard->getTile(x,y) == empty) {
            //up left: x-1, y-1
            if (gameBoard->getTile(x-1,y-1) == black) {
                if (getEndOfLine(x-1,y-1,-1,-1) == white) {
                    return true;
                }
            }

            //up: x, y-1
            if (gameBoard->getTile(x,y-1) == black) {
                if (getEndOfLine(x,y-1,0,-1) == white) {
                    return true;
                }
            }

            //up right: x+1, y-1
            if (gameBoard->getTile(x+1,y-1) == black) {
                if (getEndOfLine(x+1,y-1,1,-1) == white) {
                    return true;
                }
            }

            //left: x-1, y
            if (gameBoard->getTile(x-1,y) == black) {
                if (getEndOfLine(x-1,y,-1,0) == white) {
                    return true;
                }
            }

            //right: x+1, y
            if (gameBoard->getTile(x+1,y) == black) {
                if (getEndOfLine(x+1,y,1,0) == white) {
                    return true;
                }
            }

            //down left: x-1, y+1
            if (gameBoard->getTile(x-1,y+1) == black) {
                if (getEndOfLine(x-1,y+1,-1,+1) == white) {
                    return true;
                }
            }

            //down: x, y+1
            if (gameBoard->getTile(x,y+1) == black) {
                if (getEndOfLine(x,y+1,0,1) == white) {
                    return true;
                }
            }

            //down right: x+1, y+1
            if (gameBoard->getTile(x+1,y+1) == black) {
                if (getEndOfLine(x+1,y+1,1,1) == white) {
                    return true;
                }
            }

            else {
                return false;
            }
        }
    }
    else {
        if (gameBoard->getTile(x,y) == empty) {
            //up left: x-1, y-1
            if (gameBoard->getTile(x-1,y-1) == white) {
                if (getEndOfLine(x-1,y-1,-1,-1) == black) {
                    return true;
                }
            }

            //up: x, y-1
            if (gameBoard->getTile(x,y-1) == white) {
                if (getEndOfLine(x,y-1,0,-1) == black) {
                    qDebug("up");
                    return true;
                }
            }

            //up right: x+1, y-1
            if (gameBoard->getTile(x+1,y-1) == white) {
                if (getEndOfLine(x+1,y-1,1,-1) == black) {
                    return true;
                }
            }

            //left: x-1, y
            if (gameBoard->getTile(x-1,y) == white) {
                if (getEndOfLine(x-1,y,-1,0) == black) {
                    qDebug("left");
                    return true;
                }
            }

            //right: x+1, y
            if (gameBoard->getTile(x+1,y) == white) {
                if (getEndOfLine(x+1,y,1,0) == black) {
                    qDebug("right");
                    return true;
                }
            }

            //down left: x-1, y+1
            if (gameBoard->getTile(x-1,y+1) == white) {
                if (getEndOfLine(x-1,y+1,-1,+1) == black) {
                    return true;
                }
            }

            //down: x, y+1
            if (gameBoard->getTile(x,y+1) == white) {
                qDebug("down start");
                if (getEndOfLine(x,y+1,0,1) == black) {
                    qDebug("down");
                    return true;
                }
            }

            //down right: x+1, y+1
            if (gameBoard->getTile(x+1,y+1) == white) {
                if (getEndOfLine(x+1,y+1,1,1) == black) {
                    return true;
                }
            }

            else {
                return false;
            }
        }
    }
}

void GameEngine::makeMove(int x, int y)
{
    if (isValidMove(x,y)) {
        if (turnCount % 2 == 0) {
            gameBoard->setTile(white, x, y);
            //upper left: col-1, row-1
            if (gameBoard->getTile(x-1,y-1) == black) {
                int i = x-1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                    i++;
                    j++;
                    while(i > x && j > y) {
                        gameBoard->flipTile(i,j);
                        i++;
                        j++;
                    }
                }
            }

            //upper left: col-1, row-1
            if (gameBoard->getTile(x-1,y-1) == black) {
                int i = x-1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                    i++;
                    j++;
                    while(i < x && j < y) {
                        gameBoard->flipTile(i,j);
                        i++;
                        j++;
                    }
                }
            }

            //up: col, row-1
            if (gameBoard->getTile(x,y-1) == black) {
                int i = x;
                int j = y-1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                    j++;
                    while(j < y) {
                        gameBoard->flipTile(i,j);
                        j++;
                    }
                }
            }

            //upper right: col+1, row-1
            if (gameBoard->getTile(x+1,y-1) == black) {
                int i = x+1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i += 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                    i--;
                    j++;
                    while(i > x && j < y) {
                        gameBoard->flipTile(i,j);
                        i--;
                        j++;
                    }
                }
            }

            //left: col-1, row
            if (gameBoard->getTile(x-1,y) == black) {
                int i = x-1;
                int j = y;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                    i++;
                    while(i < x) {
                        gameBoard->flipTile(i,j);
                        i++;
                    }
                }
            }

            //right: col+1, row
            if (gameBoard->getTile(x+1,y) == black) {
                int i = x+1;
                int j = y;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i += 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                    i--;
                    while(i > x) {
                        gameBoard->flipTile(i,j);
                        i--;
                    }
                }
            }

            //bottom left: col-1, row+1
            if (gameBoard->getTile(x-1,y+1) == black) {
                int i = x-1;
                int j = y+1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j += 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                        i++;
                        j--;
                    while(i < x && j > y) {
                        gameBoard->flipTile(i,j);
                        i++;
                        j--;
                    }
                }
            }

            //down: col, row+1
            if (gameBoard->getTile(x,y+1) == black) {
                int i = x;
                int j = y+1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    j += 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                        j--;
                    while(j > y) {
                        gameBoard->flipTile(i,j);
                        j--;
                    }
                }
            }

            //bottom right: col+1, row+1
            if (gameBoard->getTile(x+1,y+1) == black) {
                int i = x+1;
                int j = y+1;
                while (gameBoard->getTile(i,j) == black && gameBoard->isValidTile(i,j)) {
                    i += 1;
                    j += 1;
                }
                if (gameBoard->getTile(i,j) == white) {
                        i--;
                        j--;
                    while(i > x && j > y) {
                        gameBoard->flipTile(i,j);
                        i--;
                        j--;
                    }
                }
            }

        }
        else {
            gameBoard->setTile(black, x, y);
            qDebug("butt");

            //upper left: col-1, row-1
            if (gameBoard->getTile(x-1,y-1) == white) {
                int i = x-1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    i++;
                    j++;
                    while(i < x && j < y) {
                        gameBoard->flipTile(i,j);
                        i++;
                        j++;
                    }
                }
            }

            //up: col, row-1
            if (gameBoard->getTile(x,y-1) == white) {
                int i = x;
                int j = y-1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    j++;
                    while(j < y) {
                        gameBoard->flipTile(i,j);
                        j++;
                    }
                }
            }

            //upper right: col+1, row-1
            if (gameBoard->getTile(x+1,y-1) == white) {
                int i = x+1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i += 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    i--;
                    j++;
                    while(i > x && j < y) {
                        gameBoard->flipTile(i,j);
                        i--;
                        j++;
                    }
                }
            }

            //left: col-1, row
            if (gameBoard->getTile(x-1,y) == white) {
                int i = x-1;
                int j = y;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    i++;
                    while(i < x) {
                        gameBoard->flipTile(i,j);
                        i++;
                    }
                }
            }

            //right: col+1, row
            if (gameBoard->getTile(x+1,y) == white) {
                qDebug("rightttt");
                int i = x+1;
                int j = y;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i += 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    i--;
                    while(i > x) {
                        gameBoard->flipTile(i,j);
                        i--;
                    }
                }
            }

            //bottom left: col-1, row+1
            if (gameBoard->getTile(x-1,y+1) == white) {
                int i = x-1;
                int j = y+1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j += 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    i++;
                    j--;
                    while(i < x && j > y) {
                        gameBoard->flipTile(i,j);
                        i++;
                        j--;
                    }
                }
            }

            //down: col, row+1
            if (gameBoard->getTile(x,y+1) == white) {
                int i = x;
                int j = y+1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    j += 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    j--;
                    while(j > y) {
                        gameBoard->flipTile(i,j);
                        j--;
                    }
                }
            }

            //bottom right: col+1, row+1
            if (gameBoard->getTile(x+1,y+1) == white) {
                int i = x+1;
                int j = y+1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i += 1;
                    j += 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    i--;
                    j++;
                    while(i > x && j > y) {
                        gameBoard->flipTile(i,j);
                        i--;
                        j--;
                    }
                }
            }
        }
    }
}

//std::unique_ptr<GameState> GameEngine::clone() const
//{

//}

std::vector<std::pair<int, int> > GameEngine::getValidMoves()
{
    std::vector<std::pair<int,int>> validMoves;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (isValidMove(x,y)) {
                qDebug("lol");
                validMoves.push_back(std::make_pair(x,y));
            }
        }
    }
    return validMoves;
}

TileState GameEngine::getEndOfLine(int x, int y, int xFac, int yFac) const
{
    if (gameBoard->getTile(x,y) == white) {
        while(gameBoard->getTile(x,y) == white && gameBoard->isValidTile(x,y)) {
            x += xFac;
            y += yFac;
        }
        return gameBoard->getTile(x,y);
    }
    else {
        while(gameBoard->getTile(x,y) == black && gameBoard->isValidTile(x,y)) {
            x += xFac;
            y += yFac;
        }
        return gameBoard->getTile(x,y);
    }
}


void GameEngine::receiveTileClick(int x, int y) {
    boardGui->disconnectTile(validMoves);
    makeMove(x,y);
    turnCount++;
    boardGui->reDrawPieces(gameBoard);
    boardGui->updateBlackScore(getBlackScore());
    boardGui->updateWhiteScore(getWhiteScore());
    if (isBlackTurn()) {
        boardGui->switchTurnBlack();
        doBlackTurn();
    }
    else {
        boardGui->switchTurnWhite();
        doWhiteTurn();
    }
}





