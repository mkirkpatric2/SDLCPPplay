//
// Created by M on 10/3/2024.
//

#ifndef TWODIMWALKGAME_SUBJECT_H
#define TWODIMWALKGAME_SUBJECT_H

#include "Observer.h"

#include <vector>

class Subject {
public:
    void attachObserver(Observer *obs){
        observers.push_back(obs);
    }
    void detachObserver();
    void notifyObserver();
private:
    std::vector<Observer *> observers;
};


#endif //TWODIMWALKGAME_SUBJECT_H
