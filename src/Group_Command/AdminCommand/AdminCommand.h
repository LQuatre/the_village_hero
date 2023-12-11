//
// Created by admin on 11/12/2023.
//

#ifndef THE_VILLAGE_HERO__ADMINCOMMAND_H
#define THE_VILLAGE_HERO__ADMINCOMMAND_H

#include "../../Game/Game.h"
#include "../Command/Command.h"

class AdminCommand : public Command {
public:
    AdminCommand();
    ~AdminCommand();
    void execute(Game& game) override;
    const std::string& getCommandName() const override;
    void inAdmin();
};


#endif //THE_VILLAGE_HERO__ADMINCOMMAND_H
