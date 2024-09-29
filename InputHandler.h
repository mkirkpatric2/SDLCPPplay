#ifndef TWODIMWALKGAME_INPUTHANDLER_H
#define TWODIMWALKGAME_INPUTHANDLER_H
#include "GameObjects/Actor.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Actor &actor) = 0;
};

class ReleaseRightCommand : public Command {
public:
    void execute (Actor &actor) override {
        actor.releaseRight();
    }
};
class ReleaseLeftCommand : public Command {
public:
    void execute (Actor &actor) override {
        actor.releaseLeft();
    }
};
class ReleaseUpCommand : public Command {
public:
    void execute (Actor &actor) override {
        actor.releaseUp();
    }
};
class ReleaseDownCommand : public Command {
public:
    void execute (Actor &actor) override {
        actor.releaseDown();
    }
};


class MoveRightCommand : public Command {
public:
    void execute(Actor &actor) override {
        actor.goRight();
    }
};


class MoveLeftCommand : public Command {
public:
    void execute(Actor &actor) override {
        actor.goLeft();
    }
};

class MoveUpCommand : public Command {
public:
    void execute(Actor &actor) override {
        actor.goUp();
    }
};

class MoveDownCommand : public Command {
public:
    void execute(Actor &actor) override {
        actor.goDown();
    }
};

class QuitCommand : public Command {
public:
    void execute(Actor &actor) override {
        SDL_Quit();
        exit(10);
    }
};



class InputHandler {
public:

    //constructor
    InputHandler(){
        buttonW = new MoveUpCommand();
        buttonA = new MoveLeftCommand();
        buttonS = new MoveDownCommand();
        buttonD = new MoveRightCommand();
        buttonESC = new QuitCommand();

        releaseButtonW = new ReleaseUpCommand();
        releaseButtonA = new ReleaseLeftCommand();
        releaseButtonS = new ReleaseDownCommand();
        releaseButtonD = new ReleaseRightCommand();
    }

    Command * handleKeyDownInput(SDL_Event e);
    Command * handleKeyUpInput(SDL_Event e);
    Command * handleInput(SDL_Event e);

    //bind commands in case of key remap. no functionality NOW.
    void bindCommandW(Command* command) { buttonW = command; }
    void bindCommandA(Command* command) { buttonA = command; }
    void bindCommandS(Command* command) { buttonS = command; }
    void bindCommandD(Command* command) { buttonD = command; }
    void bindCommandESC(Command* command) { buttonESC = command; }

private:
    Command *buttonW;
    Command *buttonA;
    Command *buttonS;
    Command *buttonD;
    Command *buttonESC;
    Command *releaseButtonW;
    Command *releaseButtonA;
    Command *releaseButtonS;
    Command *releaseButtonD;
};



#endif //TWODIMWALKGAME_INPUTHANDLER_H
