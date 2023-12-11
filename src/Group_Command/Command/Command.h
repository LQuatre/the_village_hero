//
// Created by admin on 11/12/2023.
//

#ifndef THE_VILLAGE_HERO__COMMAND_H
#define THE_VILLAGE_HERO__COMMAND_H
#include "../../Game/Game.h"

class Command {
    public:
    Command();
    ~Command();
    virtual void execute(Game& game) = 0;
    virtual const std::string& getCommandName() const = 0;
};


#endif //THE_VILLAGE_HERO__COMMAND_H
