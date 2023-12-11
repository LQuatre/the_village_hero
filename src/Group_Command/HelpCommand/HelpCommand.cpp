//
// Created by admin on 11/12/2023.
//

#include "HelpCommand.h"

HelpCommand::HelpCommand() : Command() {

}

HelpCommand::~HelpCommand() {

}

void HelpCommand::execute(Game& game) {
    game.help();
    return;
}

const std::string &HelpCommand::getCommandName() const {
    static const std::string name = "help";
    return name;
}