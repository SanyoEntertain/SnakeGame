#pragma once
#include <ncurses.h>
#include <vector>

// 실제 크기를 의미한다. width랑 height랑 다르니까.
// width가 height의 2배정도를 가져야만 동등해진다.
#define ADJUST_VAL 2

using namespace std;

class Board
{
public:
    Board(int height, int width);
    void drawMap();
    void updateMap(int y, int x, int value);
    void removeSnakes();

private:
    vector<vector<int>> map;
    int height, width;
    WINDOW *board_win;
    
    void drawCell(int y, int x, int value);
    void makeMapBorder();
};
