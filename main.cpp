// g++ -o out main.cpp snake.cpp apple.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2
//./out
#include <SDL.h>

#include "apple.h"
#include "snake.h"

int main(){
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
    SDL_SetWindowResizable(window, SDL_TRUE);
`
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    int previousBtnPress = 0;

    snake player;
    apple food;

    while(true){
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);  
        SDL_RenderClear(renderer); 
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 

        if (SDL_GetTicks() - previousBtnPress >= 75) {        
            if (keyState[SDL_SCANCODE_RIGHT]) 
               player.movePlayer(SNAKE_RIGHT);
            else if (keyState[SDL_SCANCODE_LEFT]) 
                player.movePlayer(SNAKE_LEFT);
            else if (keyState[SDL_SCANCODE_UP]) 
                player.movePlayer(SNAKE_UP);
            else if (keyState[SDL_SCANCODE_DOWN])        
                player.movePlayer(SNAKE_DOWN);
            else                 
                player.movePlayer(0);
                
            previousBtnPress = SDL_GetTicks();
        }
        
        for(int i = 0; i < player.coords.size(); i++){
            SDL_Rect block_piece;
            block_piece.x = player.coords.at(i).first;
            block_piece.y = player.coords.at(i).second;
            block_piece.w = 25;
            block_piece.h = 25;
                
            SDL_RenderFillRect(renderer, &block_piece); //draws player
        }                                            

        if(player.coords.at(0).first == food.x && player.coords.at(0).second == food.y ){ //collision detection with apple
            player.addLen();
            food.newApple();
        }

        for(int i = 1; i < player.coords.size(); i++){
            if(player.coords.at(0).first == player.coords.at(i).first 
            && player.coords.at(0).second == player.coords.at(i).second){ //collision detected with itself 
                player.resetSnake();
                food.newApple();
                break;
            }
        }

        SDL_Rect apple_piece;
        apple_piece.x = food.x;
        apple_piece.y = food.y;
        apple_piece.w = 15;
        apple_piece.h = 15;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
        SDL_RenderFillRect(renderer, &apple_piece); //draws apple

        SDL_RenderPresent(renderer);        
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)           
            break;    
    }    
    
    SDL_DestroyRenderer(renderer);   
    SDL_DestroyWindow(window);    
    SDL_Quit();    

    return 0;
}