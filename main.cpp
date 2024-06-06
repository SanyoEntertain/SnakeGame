#include <ncurses.h>
#include "src/SnakeGame.hpp"

int main(int argc, char **argv)
{
    // 게임 생성
    SnakeGame snakegame = SnakeGame();

    snakegame.startGame();
    return 0;
}
