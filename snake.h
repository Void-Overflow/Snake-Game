#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#define SNAKE_RIGHT 2
#define SNAKE_LEFT -2
#define SNAKE_DOWN 1
#define SNAKE_UP -1

class snake{
private:
    int _dir;
public:
    std::vector<std::pair<int, int> > coords;

    snake();
    void resetSnake();

    void addLen();
    void movePlayer(int dir);
};

#endif