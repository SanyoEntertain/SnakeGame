#pragma once

#include "Board.hpp"
#include "Snake.hpp"

class SnakeGame{
public:
    SnakeGame();
    void startGame();

private:
    Board board;
    Snake snake;

    bool isRunning;
    int gameDelay;

    void update();
};