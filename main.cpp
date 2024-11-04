#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "InputHandler.h"
#include "MovementManager.h"
#include "GameObjects/ActorManager.h"


#define WINDOWHEIGHT 700
#define WINDOWWIDTH 700
#define TARGET_FPS 144

int main(int argv, char** args) {


    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        SDL_Log("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    if(!IMG_Init(IMG_INIT_PNG)) {
        SDL_Log("Error initializing IMG SDL: %s\n", SDL_GetError());
        return 1;
    }

    atexit(SDL_Quit);


    SDL_Window *window = SDL_CreateWindow("Playing w/ random shit",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOWWIDTH, WINDOWHEIGHT, 0);

    if (!window)
    {
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //inst input handler, movement manager
    InputHandler inputHandler;
    MovementManager movementManager;

    // instantiate player.
    ActorManager actorManager;
    Actor player = actorManager.createPlayer(rend, &movementManager);

    //instantiate sample tree.
    Tree ftree = actorManager.createFruitTree(rend, &movementManager, 100, 100);

    //inst sample tile
    Tile tile1 = actorManager.createTileTrigger(rend, &movementManager, 255, 0, 0, 600, 600);
    Tile tile2 = actorManager.createTileTrigger(rend, &movementManager, 255, 0, 0, 500, 500);

    tile1.attachObserver(&ftree);
    tile2.attachObserver(&ftree);
    //attach ftree

    Uint32 frameStart;
    int frameTime;
    float deltaTime;


    Uint32 lastTime = SDL_GetTicks();
    while (true) {

        frameStart = SDL_GetTicks();


        SDL_Event e;
        while (SDL_PollEvent(&e)){

            //instead, going - inputhandler handle input
            Command *command = inputHandler.handleInput(e);

            if (command) {
                command->execute(player);
            }

        }



        Uint32 currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime);//in milliseconds
        lastTime = currentTime;

        movementManager.moveObjects(deltaTime);

        //add below to manager
        player.flushCollided();

        //render
        SDL_RenderClear(rend);

        ftree.renderActor(rend);
        tile1.renderTile(rend);
        tile2.renderTile(rend);
        player.renderActor(rend);

        SDL_RenderPresent(rend);


        //set framerate & wait
        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < 1000 / TARGET_FPS) {
            SDL_Delay(1000 / TARGET_FPS - frameTime);
        }





    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
