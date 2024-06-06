#pragma once

#include "Board.hpp"
#include <algorithm>
#include <deque>

using namespace std;


class Snake
{
public:
    Snake(pair<int, int> startNode);
    pair<int, int> getHead(){return headNode;}
    void move(char input);
    void draw(Board &board);

private:
    deque<pair<int, int>> snakeBody;
    pair<int, int> headNode;
    pair<int, int> preNode;
    char direction;
};