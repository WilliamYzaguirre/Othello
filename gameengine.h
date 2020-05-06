#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "guidesign.h"
#include <QObject>
#include "gamestate.h"


class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();

    const OthelloBoard& board() const noexcept;

    int getBlackScore() const noexcept;

    int getWhiteScore() const noexcept;

    bool isGameOver() const noexcept;

    bool isBlackTurn() const noexcept;

    bool isWhiteTurn() const noexcept;

    bool isValidMove(int x, int y) const noexcept;

    void makeMove(int x, int y);

    std::unique_ptr<GameState> clone() const;

    void connectGameEngine(GameEngine* ge);

public slots:
    void receiveTileClick(int, int);

private:
    GuiDesign* gui;
    GameState* gameState;

    int blackScore;
    int whiteScore;
    int turnCount;

    OthelloBoard* gameBoard;
    bool blackTurn;
    bool whiteTurn;
    std::vector<std::pair<int, int>> validBlackMoves;
    std::vector<std::pair<int, int>> validWhiteMoves;
};

#endif // GAMEENGINE_H
