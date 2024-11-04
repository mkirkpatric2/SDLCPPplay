//
// Created by M on 9/28/2024.
//

#ifndef TWODIMWALKGAME_ACTORMANAGER_H
#define TWODIMWALKGAME_ACTORMANAGER_H

#include <SDL.h>
#include "Actor.h"
#include "../MovementManager.h"
#include "Tile.h"

class ActorManager {
public:
    Actor createPlayer(SDL_Renderer *rend, MovementManager *movementManager){
        auto actRenderer = std::make_shared<ActRenderer>(rend, playerIMGs);
        auto actMover = std::make_shared<ActMover>(350, 350, 50, 50);
        Actor player = Actor(350, 350, 50, 50);
        player.setRenderer(actRenderer);
        player.setMover(actMover);
        movementManager->addMovableObject(&player);
        movementManager->addCollidableObject(&player);
        return player;
    }

    Actor createTree(SDL_Renderer *rend, MovementManager *movementManager, int x, int y){
        auto actRenderer = std::make_shared<ActRenderer>(rend, treeIMGs);
        Actor tree = Actor(x,y,50,50);
        tree.setRenderer(actRenderer);
        movementManager->addCollidableObject(&tree);
        return tree;
    }

    Tree createFruitTree(SDL_Renderer *rend, MovementManager *movementManager, int x, int y){
        auto actRenderer = std::make_shared<ActRenderer>(rend, treeIMGs);
        Tree tree = Tree(x,y,50,50, true);
        tree.setRenderer(actRenderer);
        tree.changeTexture(1);
        movementManager->addCollidableObject(&tree);
        return tree;
    }

    Tile createTileTrigger(SDL_Renderer *rend, MovementManager *movementManager, int r, int g, int b, int x, int y){
        auto actRenderer = std::make_shared<ActRenderer>(rend, treeIMGs);
        Tile tile = Tile(r, g, b, x,y,50,50);
        tile.setRenderer(actRenderer);
        movementManager->addWalkableTileObject(&tile);
        return tile;
    }

    ActorManager(){
        playerIMGs.emplace_back(R"(.\objectArt\player\chainChomp\rOpen.png)");
        treeIMGs.emplace_back(R"(.\objectArt\staticTileArt\Tree.png)");
        treeIMGs.emplace_back(R"(.\objectArt\staticTileArt\FruitTree.png)");
    }
private:
    std::vector<std::string> playerIMGs;
    std::vector<std::string> treeIMGs;
};


#endif //TWODIMWALKGAME_ACTORMANAGER_H
