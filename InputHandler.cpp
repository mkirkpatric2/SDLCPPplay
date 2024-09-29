//
// Created by M on 9/24/2024.
//

#include "InputHandler.h"

Command * InputHandler::handleKeyDownInput(SDL_Event e) {
    switch (e.key.keysym.sym) {
        case SDLK_a:
        case SDLK_LEFT:
            return buttonA;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            return buttonD;
            break;
        case SDLK_w:
        case SDLK_UP:
            return buttonW;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            return buttonS;
            break;
        case SDLK_ESCAPE:
            return buttonESC;
        default:
            return nullptr;
    }
}

Command *InputHandler::handleKeyUpInput(SDL_Event e) {
    switch (e.key.keysym.sym) {
        case SDLK_a:
        case SDLK_LEFT:
            return releaseButtonA;
        case SDLK_d:
        case SDLK_RIGHT:
            return releaseButtonD;
        case SDLK_w:
        case SDLK_UP:
            return releaseButtonW;
        case SDLK_s:
        case SDLK_DOWN:
            return releaseButtonS;
        default:
            return nullptr;
    }
}

Command *InputHandler::handleInput(SDL_Event e){
    switch (e.type) {
        case SDL_QUIT:
            SDL_Log("Clicked X\n");
            SDL_Quit();
            exit(10);
        case SDL_KEYDOWN:
            return handleKeyDownInput(e);
        case SDL_KEYUP:
            return handleKeyUpInput(e);
        default:
            return nullptr;
    }
}
