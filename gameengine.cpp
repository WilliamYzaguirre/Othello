#include "gameengine.h"

GameEngine::GameEngine()
{
    gui = new GuiDesign();
    gameState = new GameState();

    connect(gui, SIGNAL(sendTileClick(int, int)), this, SLOT(receiveTileClick(int, int)));
    gameState->connectGameEngine(this);
}

const OthelloBoard& GameEngine::board() const noexcept
{
    //const OthelloBoard retBoard = *gameBoard;
    //return retBoard;
}

int GameEngine::getBlackScore() const noexcept
{
    return blackScore;
}

int GameEngine::getWhiteScore() const noexcept
{
    return blackScore;
}

bool GameEngine::isGameOver() const noexcept
{
    if (validBlackMoves.size() == 0 && validWhiteMoves.size() == 0) {
        return true;
    }
    else {
        return false;
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
        for(std::pair<int , int> coor : validWhiteMoves) {
            if (coor == std::make_pair(x,y)) {
                return true;
            }
        }
        return false;
    }
    else {
        for(std::pair<int , int> coor : validBlackMoves) {
            if (coor == std::make_pair(x,y)) {
                return true;
            }
        }
        return false;
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
                    while(i > x && j > y) {
                        gameBoard->flipTile(i,j);
                        i--;
                        j--;
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

            //upper left: col-1, row-1
            if (gameBoard->getTile(x-1,y-1) == white) {
                int i = x-1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == black) {
                    while(i > x && j > y) {
                        gameBoard->flipTile(i,j);
                        i--;
                        j--;
                    }
                }
            }

            //upper left: col-1, row-1
            if (gameBoard->getTile(x-1,y-1) == white) {
                int i = x-1;
                int j = y-1;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard->getTile(i,j) == black) {
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
                    while(i < x) {
                        gameBoard->flipTile(i,j);
                        i++;
                    }
                }
            }

            //right: col+1, row
            if (gameBoard->getTile(x+1,y) == white) {
                int i = x+1;
                int j = y;
                while (gameBoard->getTile(i,j) == white && gameBoard->isValidTile(i,j)) {
                    i += 1;
                }
                if (gameBoard->getTile(i,j) == black) {
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

std::unique_ptr<GameState> GameEngine::clone() const
{

}


void GameEngine::receiveTileClick(int, int) {

}





