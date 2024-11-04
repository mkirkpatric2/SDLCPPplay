//
// Created by M on 9/25/2024.
//

#ifndef TWODIMWALKGAME_MOVEMENTMANAGER_H
#define TWODIMWALKGAME_MOVEMENTMANAGER_H
#include <vector>
#include "GameObjects/Actor.h"
#include "GameObjects/Tile.h"
#include <algorithm>


class MovementManager {

public:
    void addMovableObject(Actor *actor);
    void addCollidableObject(Actor *actor);
    void addWalkableTileObject(Tile *tile);
    void moveObjects(float mseconds);
    // move "shadow" objects
    // check collision with "shadow objects"
    // act appropriately
private:
    std::vector<Actor*> movableObjects;
    std::vector<Actor*> collidableObjects;
    std::vector<Tile*> walkOverCollidableObjects;
};


#endif //TWODIMWALKGAME_MOVEMENTMANAGER_H
