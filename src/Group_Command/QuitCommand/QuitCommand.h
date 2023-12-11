//
// Created by admin on 11/12/2023.
//

#ifndef THE_VILLAGE_HERO__QUITCOMMAND_H
#define THE_VILLAGE_HERO__QUITCOMMAND_H

#include "../../Game/Game.h"
#include "../Command/Command.h"

class QuitCommand : public Command {
public:
    QuitCommand();
    ~QuitCommand();
    void execute(Game& game) override;
    const std::string& getCommandName() const override;
};


#endif //THE_VILLAGE_HERO__QUITCOMMAND_H
