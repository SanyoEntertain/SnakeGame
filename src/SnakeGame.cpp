#include "SnakeGame.hpp"
#include "Snake.hpp"
#include <unistd.h>
#include "Input.h"

#include <iostream>

using namespace std;

SnakeGame::SnakeGame() : board(0, 0), snake((pair<int, int>){0, 0})
{
    initscr();

    isRunning = true;
    // gameDelay 설정
    gameDelay = 1;

    // 전체 판의 크기
    int board_width = 21;
    int board_height = 21;

    // Board를 생성하고 그림.
    board = Board(board_height, board_width);

    // 플레이어(뱀) 생성
    snake = Snake(pair<int, int>{board_height / 2, board_width / 2});

    snake.draw(board);

    // 맵 그리기
    board.drawMap();
}

// 게임 시작
void SnakeGame::startGame()
{
    noecho();
    // 커서 감추기
    curs_set(0);
    // keypad 활성화
    keypad(stdscr, TRUE);
    // 비동기 활성
    nodelay(stdscr, TRUE);

    while (isRunning)
    {
        update();
        sleep(gameDelay);
    }
    endwin();
}

void SnakeGame::update()
{
    // 아이템 생성, 죽었는지 확인, 플레이어 움직임 등등
    snake.move(getInput());
    snake.draw(board);

    board.drawMap();
}