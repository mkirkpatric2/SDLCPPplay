//
// Created by M on 10/3/2024.
//

#ifndef TWODIMWALKGAME_TILE_H
#define TWODIMWALKGAME_TILE_H

#include <memory>
#include "./Observer.h"
#include "./Subject.h"
#include "Components/ActRenderer.h"

//Like actor. No movement. Rendering will be colors NOT images.
class Tile : public Observer, public Subject {
public:
    //return rect and info
    SDL_Rect *getRect(){return rect;}
    int getRectX(){return rect->x;}
    int getRectY(){return rect->y;}

    //assign Renderer Functions
    void setRenderer(std::shared_ptr<ActRenderer> renderer);
    void renderTile(SDL_Renderer *rend);

    //constructor
    Tile(int r, int g, int b, int xCoord, int yCoord, int height, int width){
        red = r;
        green = g;
        blue = b;
        rect = new SDL_Rect;
        rect->x = xCoord;
        rect->y = yCoord;
        rect->h = height;
        rect->w = width;
    }

    void update() override {}




private:
    //Major Components
    std::shared_ptr<ActRenderer> actRenderer;
    SDL_Rect *rect;

    //color for tile
    int red;
    int green;
    int blue;
};


#endif //TWODIMWALKGAME_TILE_H
