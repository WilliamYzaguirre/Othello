#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "othelloboard.h"
#include "gameengine.h"


class GameState
{
public:
    GameState();

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

private:
    int blackScore;
    int whiteScore;
    int turnCount;

    OthelloBoard* gameBoard;
    bool blackTurn;
    bool whiteTurn;
    std::vector<std::pair<int, int>> validBlackMoves;
    std::vector<std::pair<int, int>> validWhiteMoves;

    GameEngine* gameEngine;
};

#endif // GAMESTATE_H
