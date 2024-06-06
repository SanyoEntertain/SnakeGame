#include "Snake.hpp"

Snake::Snake(pair<int, int> startNode) : headNode(startNode)
{
    // 뱀 초기화
    snakeBody.clear();
    snakeBody.push_back(startNode);
    snakeBody.push_back((pair<int, int>){startNode.first + 1, startNode.second});
    snakeBody.push_back((pair<int, int>){startNode.first + 2, startNode.second});

    headNode = startNode;
    preNode = make_pair(999999, 99999);

    direction = 'U';
}

// 뱀 그리기
void Snake::draw(Board &board)
{
    // 먼저 원래 뱀들 없애고 다시 그린다.
    board.removeSnakes();
    // head 그리기
    board.updateMap(headNode.first, headNode.second, 3);
    // 나머지 그리기
    for (int i = 1; i < snakeBody.size(); i++)
    {
        board.updateMap(snakeBody[i].first, snakeBody[i].second, 4);
    }

    board.drawMap();
}

void Snake::move(char input)
{
    // 무빙 메커니즘: 정해진 방향으로 앞에 있는 노드만 변하고, 뒤의 노드를 삭제하면 된다.
    // head가 움직일 노드만 방향별로 정해주면 된다.
    pair<int, int> tmpPoint;
    switch (input)
    {
    case 'U':
        tmpPoint = make_pair(headNode.first - 1, headNode.second);
        direction = 'U';
        break;
    case 'L':
        tmpPoint = make_pair(headNode.first, headNode.second - 1);
        direction = 'L';
        break;
    case 'R':
        tmpPoint = make_pair(headNode.first, headNode.second + 1);
        direction = 'R';
        break;
    case 'D':
        tmpPoint = make_pair(headNode.first + 1, headNode.second);
        direction = 'D';
        break;
    case 'X':
        move(direction);
        return;
    }
    snakeBody.push_front(tmpPoint);
    snakeBody.pop_back();
    preNode = headNode;
    headNode = tmpPoint;
}
