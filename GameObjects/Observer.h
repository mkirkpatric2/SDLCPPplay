//
// Created by M on 10/3/2024.
//

#ifndef TWODIMWALKGAME_OBSERVER_H
#define TWODIMWALKGAME_OBSERVER_H
#include "./Subject.h"

class Observer {
public:
    virtual void update() = 0;
};


#endif //TWODIMWALKGAME_OBSERVER_H
