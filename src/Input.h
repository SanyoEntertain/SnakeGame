#ifndef _Input_H
#define _Input_H
#include <ncurses.h>

// input을 받는다.
char getInput()
{
    int input = getch();
    char retCh;
    switch (input)
    {
    case KEY_UP:
        retCh = 'U';
        break;
    case KEY_LEFT:
        retCh = 'L';

        break;
    case KEY_RIGHT:
        retCh = 'R';

        break;
    case KEY_DOWN:
        retCh = 'D';

        break;
    default:
        retCh = 'X';
        break;
    }

    return retCh;
}
#endif