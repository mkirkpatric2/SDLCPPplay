//
// Created by M on 10/3/2024.
//

#include "Tile.h"

void Tile::renderTile(SDL_Renderer *rend) {
    if(actRenderer){
        actRenderer->renderTile(rend, rect, red, green, blue);
    } else {
        //ERROR HANDLE
        SDL_Log("No renderer Present in Actor XX");
    }
}

void Tile::setRenderer(std::shared_ptr<ActRenderer> renderer) {
    this->actRenderer = renderer;
}
