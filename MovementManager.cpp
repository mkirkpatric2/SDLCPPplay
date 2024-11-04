//
// Created by M on 9/25/2024.
//

#include "MovementManager.h"
#include "GameObjects/Actor.h"


char checkCollision(Actor *mover, Actor *object) {

    if(SDL_HasIntersection(mover->getRect(), object->getRect())){

        std::vector<int> rectA = mover->getFutureInfoXYWH();
        std::vector<int> rectB = object->getFutureInfoXYWH();
//        SDL_Log("%d -- %d compare", rectA.at(0), rectB.at(0));

        int rectARightCollision = rectA.at(0) + rectA.at(2) - rectB.at(0);    // Right edge of A to left edge of B
        int rectALeftCollision = rectB.at(0) + rectB.at(2) - rectA.at(0);   // Right edge of B to left edge of A
        int rectABotCollision = rectA.at(1) + rectA.at(3) - rectB.at(1);      // Bottom edge of A to top edge of B
        int rectATopCollision = rectB.at(1) + rectB.at(3) - rectA.at(1);   // Bottom edge of B to top edge of A

        int minOverlap = std::min({rectATopCollision, rectARightCollision, rectALeftCollision, rectABotCollision});

        if (minOverlap == rectARightCollision) {
            return 'R';
        } else if (minOverlap == rectALeftCollision) {
            return 'L';
        } else if (minOverlap == rectABotCollision) {
            return 'D';
        } else if (minOverlap == rectATopCollision) {
            return 'U';
        } else return 'N';

    }
    return 'N';
}


void MovementManager::moveObjects(float mseconds) {


    for (auto& movIt: movableObjects) {
        movIt->calcFuturePosition(mseconds);
        std::vector<int> futureBox = movIt->getFutureInfoXYWH();
        int startX = movIt->getRectX();
        int startY = movIt->getRectY();


        //address non-walkable collisions
        for (auto& colObjs: collidableObjects) {
            if(&*colObjs != &*movIt){ // Is the address of the the thing colobjs points to same as ....
                char collisionLocation;
                if ((collisionLocation = checkCollision(movIt, colObjs)) != 'N'){
                    movIt->pushCollisionBorder(collisionLocation);
                }
            }
        }

        //address walkable collisions
        for (auto& walkObj: walkOverCollidableObjects) {
            if(SDL_HasIntersection(movIt->getRect(), walkObj->getRect())){
                walkObj->notifyObserver(true);
            }
        }

        //FILL ***


        // At this speed, I do overlap by one pixel. Maybe I wrap tiles in a second square 1px greater and check against that?
        for(auto& collidedBorders: movIt->readCollidedBorders()){
            switch (collidedBorders){
                case 'D':
                    if(futureBox[1] > startY) movIt->collidedFuturePosition(1, movIt->getRectY());
                    break;
                case 'U':
                    if(futureBox[1] < startY) movIt->collidedFuturePosition(1, movIt->getRectY());
                    break;
                case 'R':
                    if(futureBox[0] > startX) movIt->collidedFuturePosition(0, movIt->getRectX());
                    break;
                case 'L':
                    if(futureBox[0] < startX) movIt->collidedFuturePosition(0, movIt->getRectX());
                    break;
                case 'N':
                default:
                    break;
            }
        }

        movIt->moveObject();
        //celar vector


    }





    for (auto& it: movableObjects) {
        it->moveObject();
    }

}



void MovementManager::addMovableObject(Actor *actor) {
    movableObjects.push_back(actor);
}

void MovementManager::addCollidableObject(Actor *actor) {
    collidableObjects.push_back(actor);
}

void MovementManager::addWalkableTileObject(Tile *tile) {
    walkOverCollidableObjects.push_back(tile);
}
