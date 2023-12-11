//
// Created by admin on 11/12/2023.
//
#include "CodeCommand.h"

CodeCommand::CodeCommand() : Command() {

}

CodeCommand::~CodeCommand() {

}

void CodeCommand::execute(Game& game) {
    return;
}

const std::string &CodeCommand::getCommandName() const {
    static const std::string name = "code";
    return name;
}

