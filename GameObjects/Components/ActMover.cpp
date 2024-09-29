//
// Created by M on 9/28/2024.
//

#include "ActMover.h"

#define PLAYER_SPEED_PER_SEC 100


void ActMover::calcFuturePosition(float mseconds) {
    float toMove = 0;
    if (!xMovement.empty() || !yMovement.empty()) toMove = (mseconds*PLAYER_SPEED_PER_SEC)/1000;

    if(toMove < 1) {
        moveFraction += toMove;
    }

    if (moveFraction >= 1){

        if (!xMovement.empty()){
            if (xMovement.back() == 'R') futureXYWH[0] += 1;
            else if (xMovement.back() == 'L') futureXYWH[0] -= 1;
        }

        if (!yMovement.empty()){
            if (yMovement.back() == 'U') futureXYWH[1]  -= 1;
            else if (yMovement.back() == 'D') futureXYWH[1]  += 1;
        }

        moveFraction -= 1;
    }

//    SDL_Log("Coords: x: %d y: %d ", futureXYWH[0], futureXYWH[1]);
}
void ActMover::pushCollisionBorder(char border) {
    collisionBorders.push_back(border);
}

std::vector<char> ActMover::readCollidedBorders() {
    return collisionBorders;
}

void ActMover::collidedFuturePosition(int coord, int value) {
    futureXYWH[coord] = value;
}

std::vector<int> ActMover::getFutureInfoXYWH() const {
    return futureXYWH;
}

void ActMover::moveObject(SDL_Rect *rect) {
    rect->x = futureXYWH[0];
    rect->y = futureXYWH[1];

}

//up down left right

void ActMover::goUp() {
    auto it = yMovement.begin();
    if (it == yMovement.end()) yMovement.push_back('U');
    else if (*it != 'U') { //if first entry isn't End or L.
        ++it;
        if (it == yMovement.end()){
            yMovement.push_back('U'); // if second entry is end, add L to vector at front.
        }else if (*it == 'U'){
            yMovement.erase(it);
            yMovement.push_back('U');
        } else yMovement.clear();
    }
}

void ActMover::goDown() {
    auto it = yMovement.begin();
    if (it == yMovement.end()) yMovement.push_back('D');
    else if (*it != 'D') { //if first entry isn't End or L.
        ++it;
        if (it == yMovement.end()){
            yMovement.push_back('D'); // if second entry is end, add L to vector at front.
        }else if (*it == 'D'){
            yMovement.erase(it);
            yMovement.push_back('D');
        } else yMovement.clear();
    }
}


void ActMover::goLeft() {
    auto it = xMovement.begin();
    if (it == xMovement.end()) xMovement.push_back('L');
    else if (*it != 'L') { //if first entry isn't End or L.
        ++it;
        if (it == xMovement.end()){
            xMovement.push_back('L'); // if second entry is end, add L to vector at front.
        }else if (*it == 'L'){
            xMovement.erase(it);
            xMovement.push_back('L');
        } else xMovement.clear();
    }
}

void ActMover::goRight() {
    auto it = xMovement.begin();
    if (it == xMovement.end()) xMovement.push_back('R');
    else if (*it != 'R') { //if first entry isn't End or L.
        ++it;
        if (it == xMovement.end()){
            xMovement.push_back('R'); // if second entry is end, add L to vector at front.
        }else if (*it == 'R'){
            xMovement.erase(it);
            xMovement.push_back('R');
        } else xMovement.clear();
    }
}

void ActMover::releaseLeft() {
    auto it = xMovement.begin();
    if (*it == 'L'){
        xMovement.erase(it);
    } else {
        ++it;
        if (*it == 'L'){
            xMovement.erase(it);
        }
    }
}

void ActMover::releaseRight() {
    auto it = xMovement.begin();
    if (*it == 'R'){
        xMovement.erase(it);
    } else {
        ++it;
        if (*it == 'R'){
            xMovement.erase(it);
        }
    }
}

void ActMover::releaseUp() {
    auto it = yMovement.begin();
    if (*it == 'U'){
        yMovement.erase(it);
    } else {
        ++it;
        if (*it == 'U'){
            yMovement.erase(it);
        }
    }
}

void ActMover::releaseDown() {
    auto it = yMovement.begin();
    if (*it == 'D'){
        yMovement.erase(it);
    } else {
        ++it;
        if (*it == 'D'){
            yMovement.erase(it);
        }
    }
}

void ActMover::flushCollided() {
    collisionBorders.clear();
}

ActMover::ActMover(int x, int y, int w, int h) {
    moveFraction = 0;
    movingNo = 0;
    futureXYWH.push_back(x);
    futureXYWH.push_back(y);
    futureXYWH.push_back(w);
    futureXYWH.push_back(h);
}
