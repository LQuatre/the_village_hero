//
// Created by admin on 11/12/2023.
//

#include "AdminCommand.h"


AdminCommand::AdminCommand() : Command() {

}

AdminCommand::~AdminCommand() {

}

void AdminCommand::inAdmin() {
    // TODO: Implement admin commands and quit admin mode
}

void AdminCommand::execute(Game& game) {
    if (game.getPlayerPtr()->getAdmin()) {
        inAdmin();
    } else {
        std::cout << "Enter admin password: ";
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
        int c;
        while ((c = std::cin.get()) != '\n' && c != EOF);
        std::string s;
        getline(std::cin, s);
        if (s == "RocketLeague2023") {
            game.getPlayerPtr()->setAdmin(true);
            inAdmin();
            return;
        }
        std::cout << "Incorrect password.\n";
    }
    return;
}

const std::string &AdminCommand::getCommandName() const {
    static const std::string name = "admin";
    return name;
}