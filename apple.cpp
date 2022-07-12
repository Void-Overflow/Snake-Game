#include "apple.h"

#include <random>

apple::apple(){
    srand(time(NULL));
    newApple();
}

void apple::newApple(){
    int multiOfY[23];
    multiOfY[0] = 25;
    for (int y = 1; y < 23; y++)
        multiOfY[y] = multiOfY[y-1] + 25;

    int multiOfX[31];
    multiOfX[0] = 25;
    for (int x = 1; x < 31; x++)
        multiOfX[x] = multiOfX[x-1] + 25;

    y = multiOfY[rand() % 23 + 0];
    x = multiOfX[rand() % 31 + 0];
}