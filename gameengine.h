#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "gamestate.h"
#include "guidesign.h"
#include <othelloboard.h>
#include <QObject>
#include "boardgui.h"


class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();

    void run();

    void doWhiteTurn();

    void doBlackTurn();

    const OthelloBoard& board() const noexcept;

    int getBlackScore() const noexcept;

    int getWhiteScore() const noexcept;

    void endGame() noexcept;

    bool isBlackTurn() const noexcept;

    bool isWhiteTurn() const noexcept;

    bool isValidMove(int x, int y) const noexcept;

    void makeMove(int x, int y);

    //std::unique_ptr<GameState> clone() const;

    void connectGameEngine(GameEngine* ge);

    std::vector<std::pair<int,int>> getValidMoves();

    TileState getEndOfLine(int x, int y, int xFac, int yFac) const;

public slots:
    void receiveTileClick(int, int);

private:
    GuiDesign* gui;
    //GameState* gameState;
    BoardGui* boardGui;

    int blackScore;
    int whiteScore;
    int turnCount;

    bool gameOverTest;
    bool gameOver;

    OthelloBoard* gameBoard;
    bool blackTurn;
    bool whiteTurn;
    std::vector<std::pair<int, int>> validMoves;
    //std::vector<std::pair<int, int>> validWhiteMoves;
};

#endif // GAMEENGINE_H
