//
// Created by admin on 11/12/2023.
//

#include "QuitCommand.h"

QuitCommand::QuitCommand() : Command() {

}

QuitCommand::~QuitCommand() {

}

void QuitCommand::execute(Game& game) {
    if (!game.IsRunning()) {
        std::cout << "Game is not running" << std::endl;
        return;
    }
    std::cout << "You quit the game" << std::endl;
    game.setRunning(false);
    return;
}

const std::string &QuitCommand::getCommandName() const {
    static const std::string name = "quit";
    return name;
}
