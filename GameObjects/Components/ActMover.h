//
// Created by M on 9/28/2024.
//

#ifndef TWODIMWALKGAME_ACTMOVER_H
#define TWODIMWALKGAME_ACTMOVER_H

#include <SDL.h>
#include <vector>

class ActMover {
public:
    //movement commands. Intend to rewrite into vector based system.
    void goUp();
    void goDown();
    void releaseUp();
    void releaseDown();
    void goLeft();
    void goRight();
    void releaseLeft();
    void releaseRight();
    //collision
    void calcFuturePosition(float mseconds);
    void collidedFuturePosition(int coord, int value);
    void pushCollisionBorder(char border);
    [[nodiscard]] std::vector<char> readCollidedBorders();
    [[nodiscard]] std::vector<int> getFutureInfoXYWH() const;
    void flushCollided();
    //move it
    void moveObject(SDL_Rect *rect);

    //construct
    explicit ActMover(int x, int y, int w, int h);
private:
    float moveFraction;
    int movingNo;
    std::vector<char> xMovement;
    std::vector<char> yMovement;
    std::vector<int> futureXYWH;
    std::vector<char> collisionBorders;
};


#endif //TWODIMWALKGAME_ACTMOVER_H
