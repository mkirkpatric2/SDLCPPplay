//
// Created by M on 10/3/2024.
//

#ifndef TWODIMWALKGAME_SUBJECT_H
#define TWODIMWALKGAME_SUBJECT_H

#include "Observer.h"
#include <algorithm>
#include <vector>

class Subject {
public:
    void attachObserver(Observer *obs){
        observers.push_back(obs);
    }
//    void detachObserver(){};

    void notifyObserver(bool remove){
        for (auto& it : observers){
            it->update();

            if(remove){
                it = nullptr;
            }
        }
        observers.erase(std::remove(observers.begin(), observers.end(), nullptr), observers.end());
    }
private:
    std::vector<Observer *> observers;
};


#endif //TWODIMWALKGAME_SUBJECT_H
