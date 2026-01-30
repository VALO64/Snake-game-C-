#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

#define WIDTH 900
#define HEIGHT 600
#define WHITE  0xffffffff
#define BLACK  0xff000000
#define GREEN  0xff00ff00
// Logic to determinate the size of the squares
#define INCREMENT_COLUMNS WIDTH/28
#define INCREMENT_ROWS HEIGHT/18

void background_paint(SDL_Surface *background){
    // Background columns lines 
    SDL_Rect back_columns;
    back_columns.x = 0;
    back_columns.y = 0;
    back_columns.w = 3;
    back_columns.h = HEIGHT;
    // Background rows lines
    SDL_Rect back_rows; //x y w h
    back_rows.x = 0;
    back_rows.y = 0;
    back_rows.w = WIDTH;
    back_rows.h = 3;

    for (int i = 0; i < INCREMENT_COLUMNS; i++){
        //std::cout << "i: " << i << std::endl; //Test columns logic 
        back_columns.x = i * INCREMENT_COLUMNS;
        SDL_FillRect (background, &back_columns,BLACK);

    }
    for (int j = 0; j < INCREMENT_ROWS; j++){
        //std::cout << "j: " << j << std::endl; //Test rows logic
        back_rows.y = j * INCREMENT_ROWS;
        SDL_FillRect (background, &back_rows,BLACK);
    }
}
struct snake_m{

};
void snake(SDL_Surface *background, int dxm, int dym){
    SDL_Rect snake_movement;
    snake_movement.x = dxm;
    snake_movement.y = dym;
    snake_movement.w = (INCREMENT_COLUMNS) - 3;
    snake_movement.h = (INCREMENT_ROWS) - 3;
    SDL_FillRect (background, &snake_movement,GREEN);
}
int main (){
    std::cout << "Hello this is a snake game!\n";
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *psurface = SDL_CreateWindow("Snake game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Surface *background = SDL_GetWindowSurface(psurface);
    SDL_FillRect (background, NULL, WHITE);

    background_paint(SDL_GetWindowSurface(psurface));
    //snake(SDL_GetWindowSurface(psurface), 3,3);
    SDL_UpdateWindowSurface(psurface);
    SDL_Event event;
    bool quit = false;
    int dym = 0;
    int dymm = 0;
    int dxm = 0;
    int dxmm = 0;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
            quit = true;
            }
            SDL_GetKeyboardState(NULL);
            if(event.key.keysym.sym == SDLK_DOWN){
                //SDL_Delay(10);
                dymm ++;
                dym = dymm * INCREMENT_ROWS;
                std::cout << "Hey down was pressed\n";
                snake(SDL_GetWindowSurface(psurface), dxm + 3,dym + 3);
                SDL_UpdateWindowSurface(psurface);    
            }
            if(event.key.keysym.sym == SDLK_UP){
                //SDL_Delay(10);
                dymm --;
                dym = dymm * INCREMENT_ROWS;
                std::cout << "Hey up was pressed\n";
                snake(SDL_GetWindowSurface(psurface), dxm + 3,dym + 3);
                SDL_UpdateWindowSurface(psurface);    
            }
            if(event.key.keysym.sym == SDLK_RIGHT){
                //SDL_Delay(10);
                dxmm ++;
                dxm = dxmm * INCREMENT_COLUMNS;
                std::cout << "Hey right was pressed\n";
                snake(SDL_GetWindowSurface(psurface), dxm + 3 ,dym + 3);
                SDL_UpdateWindowSurface(psurface);    
            }
            if(event.key.keysym.sym == SDLK_LEFT){
                //SDL_Delay(10);
                dxmm --;
                dxm = dxmm * INCREMENT_COLUMNS;
                std::cout << "Hey right was pressed\n";
                snake(SDL_GetWindowSurface(psurface), dxm + 3 ,dym + 3);
                SDL_UpdateWindowSurface(psurface);    
            }
            //snake(SDL_GetWindowSurface(psurface), 3,dym);
            SDL_UpdateWindowSurface(psurface);
            SDL_Delay(100);
        }


    }

                                            
    return 0;
    
}