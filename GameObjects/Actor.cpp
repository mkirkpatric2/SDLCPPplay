//
// Created by M on 9/28/2024.
//

#include "Actor.h"

void Actor::setRenderer(std::shared_ptr<ActRenderer> renderer) {
    this->actRenderer = renderer;
}
void Actor::setMover(std::shared_ptr<ActMover> mover) {
    this->actMover = mover;
}

void Actor::renderActor(SDL_Renderer *rend) {
    if(actRenderer){
        actRenderer->renderActor(rend, rect);
    } else {
        //ERROR HANDLE
        SDL_Log("No renderer Present in Actor XX");
    }
}

void Actor::changeTexture(int frame) {
    if(actRenderer){
        actRenderer->setObjectTexture(frame);
    } else {
        //ERROR HANDLE
        SDL_Log("No renderer Present in Actor XX");
    }
}

void Actor::goUp() {
    if(actMover){
        actMover->goUp();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

void Actor::goDown() {
    if(actMover){
        actMover->goDown();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}
void Actor::goLeft() {
    if(actMover){
        actMover->goLeft();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}
void Actor::goRight() {
    if(actMover){
        actMover->goRight();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}
void Actor::releaseUp() {
    if(actMover){
        actMover->releaseUp();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}
void Actor::releaseDown() {
    if(actMover){
        actMover->releaseDown();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}
void Actor::releaseLeft() {
    if(actMover){
        actMover->releaseLeft();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}
void Actor::releaseRight() {
    if(actMover){
        actMover->releaseRight();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

void Actor::calcFuturePosition(float mseconds) {
    if(actMover){
        actMover->calcFuturePosition(mseconds);
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

void Actor::collidedFuturePosition(int coord, int value) {
    if(actMover){
        actMover->collidedFuturePosition(coord, value);
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

void Actor::pushCollisionBorder(char border) {
    if(actMover){
        actMover->pushCollisionBorder(border);
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

std::vector<char> Actor::readCollidedBorders() {
    if (actMover){
        return actMover->readCollidedBorders();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

std::vector<int> Actor::getFutureInfoXYWH() const {
    if (actMover){
        return actMover->getFutureInfoXYWH();
    } else {
        std::vector<int> notMoving;
        notMoving.push_back(rect->x);
        notMoving.push_back(rect->y);
        notMoving.push_back(rect->w);
        notMoving.push_back(rect->h);
        return notMoving;
    }
}

void Actor::flushCollided() {
    if(actMover){
        actMover->flushCollided();
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}

void Actor::moveObject() {
    if(actMover){
        actMover->moveObject(rect);
    } else {
        //ERROR HANDLE
        SDL_Log("No Mover Present in Actor XX");
    }
}







//Player::Player(SDL_Renderer *rend, MovementManager *movementManager) {
//    // Establish rectangle
//    rect = new SDL_Rect;
//    rect->h = 50;
//    rect->w = 50;
//    rect->x = 350;
//    rect->y = 350;
//    moveFraction = 0;
//    movingNo = 0;
//
//    // ID
//    id = 1;
//
//    //set future values starting position
//    futureXYWH.push_back(350);
//    futureXYWH.push_back(350);
//    futureXYWH.push_back(50);
//    futureXYWH.push_back(50);
//
//
//
//    // Add to manager
//    movementManager->addMovableObject(this);
//    movementManager->addCollidableObject(this);
//
//    //add art filepaths
//    imgPaths.push_back("./objectArt/rOpen.png");
//    imgPaths.push_back("./objectArt/rMid.png");
//
//    // Prep texture
//    actorIMG = IMG_Load(imgPaths[0].c_str());
//    actorIMG2 = IMG_Load(imgPaths[1].c_str());
//    actorTexture = SDL_CreateTextureFromSurface(rend, actorIMG);
//    actorTexture2 = SDL_CreateTextureFromSurface(rend, actorIMG2);
//    renderTexture = actorTexture;
//
//
//}
//
//void Player::moveObject() {
//    //shitty animation logic lol
//    if ( !xMovement.empty() || !yMovement.empty()){
//        movingNo++;
//        if (movingNo%240 > 119){
//            renderTexture = actorTexture2;
//        } else {
//            renderTexture = actorTexture;
//        }
//
//        if (movingNo>720)movingNo = 0;
//
//    } else {
//        renderTexture = actorTexture;
//    }
//    ActorDep::moveObject();
//}


