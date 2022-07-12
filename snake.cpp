#include "snake.h"

snake::snake(){
    coords.push_back(std::make_pair(250, 250));
    _dir = SNAKE_RIGHT; //default direction on startup
}

void snake::resetSnake(){
    coords.clear();
    
    coords.push_back(std::make_pair(250, 250));
    _dir = SNAKE_RIGHT; //default direction on startup
}

void snake::addLen(){
    coords.push_back(std::make_pair(coords.back().first, coords.back().second));
    movePlayer(0);
}

void snake::movePlayer(int dir){
    if(dir != 0){
        if(_dir == -dir)
            _dir = -dir; //prevents player from going in a negative direction
        else
            _dir = dir;
    }

    //Moves each segment to the last position of the one in front of it
    for(int i = coords.size() - 1; i >= 1; i--){
        coords.at(i).first = coords.at(i - 1).first;
        coords.at(i).second = coords.at(i - 1).second;
    }

    switch(_dir){ //Moves the snake's head
        case SNAKE_DOWN:
            coords.at(0).second += 25;    
            break;
        case SNAKE_UP:
            coords.at(0).second -= 25;
            break;
        case SNAKE_LEFT:
            coords.at(0).first -= 25;
            break;
        case SNAKE_RIGHT:
            coords.at(0).first += 25;
            break;
    }

    //X-Axis bounds detection
    if(coords.at(0).first < 0)
        coords.at(0).first = 0; 
    
    else if(coords.at(0).first >= 775)
        coords.at(0).first = 775;
    
     //Y-Axis bounds detection
    if(coords.at(0).second < 0)
        coords.at(0).second = 0; 
    
    else if(coords.at(0).second >= 575)
        coords.at(0).second = 575; 
}