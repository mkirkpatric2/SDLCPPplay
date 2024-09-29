//
// Created by M on 9/28/2024.
//

#ifndef TWODIMWALKGAME_ACTOR_H
#define TWODIMWALKGAME_ACTOR_H
#include <SDL.h>
#include <vector>
#include <string>
#include <memory>
#include "Components/ActRenderer.h"
#include "Components/ActMover.h"


class Actor {
public:
    //return rect and info
    SDL_Rect *getRect(){return rect;}
    int getRectX(){return rect->x;}
    int getRectY(){return rect->y;}

    //assign component functions
    void setRenderer(std::shared_ptr<ActRenderer> renderer);
    void setMover(std::shared_ptr<ActMover> mover);

    //assign Renderer Functions
    void renderActor(SDL_Renderer *rend);
    void changeTexture(int frame);

    //Assign Mover functions
    //keypress functions first
    void goUp();
    void goDown();
    void releaseUp();
    void releaseDown();
    void goLeft();
    void goRight();
    void releaseLeft();
    void releaseRight();

    //Collision foos
    void calcFuturePosition(float mseconds);
    void collidedFuturePosition(int coord, int value);
    void pushCollisionBorder(char border);
    [[nodiscard]] std::vector<char> readCollidedBorders();
    [[nodiscard]] std::vector<int> getFutureInfoXYWH() const;
    void flushCollided();

    void moveObject();

    Actor(int xCoord, int yCoord, int height, int width){
        rect = new SDL_Rect;
        rect->x = xCoord;
        rect->y = yCoord;
        rect->h = height;
        rect->w = width;
    }

private:
    //Major Components
    std::shared_ptr<ActRenderer> actRenderer;
    std::shared_ptr<ActMover> actMover;

    SDL_Rect *rect;
};



#endif //TWODIMWALKGAME_ACTOR_H
