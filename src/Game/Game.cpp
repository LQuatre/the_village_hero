//
// Created by admin on 30/11/2023.
//

#include "Game.h"
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Village/Village.h"
#include "../Quete/Quete.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include "../Group_Command/Command/Command.h"
#include "../Group_Command/HelpCommand/HelpCommand.h"
#include "../Group_Command/QuitCommand/QuitCommand.h"
#include "../Group_Command/AdminCommand/AdminCommand.h"
#include "../Group_Command/CodeCommand/CodeCommand.h"

bool ativatedFreeGold = false;

Game::Game()     {
    m_village = new Village();
    m_village->setName("konoha");
    m_village->generateBuildings();
    m_village->displayBuildings();
    m_villages.push_back(m_village);

    Character& thisChar = *new Character(100, 10, nullptr);
    m_characters.push_back(&thisChar);
    m_player = new Player();
    m_player->setCharacter(thisChar);
    m_players.push_back(m_player);

    Quete& quete1 = *new Quete("quete1", "Enter in " + m_village->getBuildingsByType("Mine")[1]->getName(), "enter "+m_village->getBuildings()[1]->getName(), 1, 1, 5);
    m_quetes.push_back(&quete1);
    Quete& quete2 = *new Quete("quete2", "quete2", "player have >20 gold", 1, 1, 5);
    m_quetes.push_back(&quete2);
}

Game::~Game() {

}

bool Game::IsRunning() const {
    return m_isRunning;
}

void Game::start() {
    m_isRunning = true;

    clearTerminal();

    std::cout << "Bienvenue dans le jeu du Hero du village !" << std::endl;
    std::cout << "Vous etes dans le village de " << m_village->getName() << std::endl;
    std::cout << "Vous etes " << m_player->getCharacter().getName() << std::endl;
    std::cout << "Vous avez " << m_player->getCharacter().getHealth() << " points de vie" << std::endl;
    std::cout << "Vous avez " << m_player->getCharacter().getGold() << " pieces d'or" << std::endl;

    playerLevelUp();
    run();
}

void Game::run() {
    while (IsRunning()) {
        if (m_player->getCharacter().getHealth() <= 0) {
            std::cout << "Vous etes mort" << std::endl;
            m_isRunning = false;
        }
        if (m_player->getCharacterPtr()->getGold() > 20) {
            playerAction("player have >20 gold");
        }
        Input();
    }
}

void Game::clearTerminal() {
//    std::cout << "\x1B[2J\x1B[H";
}

void Game::Input() {
    Game& game = *this;
    std::cout << std::endl << "What do you want to do ?" << std::endl;

    std::string input;
    std::cin >> input;

    HelpCommand helpCommand;
    QuitCommand quitCommand;
    AdminCommand adminCommand;
    CodeCommand codeCommand;

    std::vector<Command*> commands;
    commands.push_back(&helpCommand);
    commands.push_back(&quitCommand);
    commands.push_back(&adminCommand);
    commands.push_back(&codeCommand);

    for (int i = 0; i < commands.size(); i++) {
        if (input == commands[i]->getCommandName()) {
            commands[i]->execute(*this);
            return;
        }
    }
    std::cout << "Command not found" << std::endl;
}

void Game::help() {
    std::cout << "Command list available:" << std::endl;
    std::cout << "help" << std::endl;
    std::cout << "quit" << std::endl;
    std::cout << "stats" << std::endl;
    if (m_player->getAdmin()) {
        std::cout << "admin" << std::endl;
        std::cout << "addGold" << std::endl;
        std::cout << "removeGold" << std::endl;
        std::cout << "setGold" << std::endl;
        std::cout << "addHealth" << std::endl;
        std::cout << "removeHealth" << std::endl;
        std::cout << "setHealth" << std::endl;
    }
}

void Game::playerAction(std::string action) {
    for (int i = 0; i < m_quetes.size(); i++) {
        if (action == m_activeQuetes[i]->getAction()) {
            std::cout << "Vous avez termine la quete : " << m_activeQuetes[i]->getName() << std::endl;
            m_player->getCharacterPtr()->addExperience(m_activeQuetes[i]->getExp());
            m_player->getCharacterPtr()->addGold(m_activeQuetes[i]->getGold());
            std::cout << "Vous avez gagne " << m_activeQuetes[i]->getExp() << " points d'experience" << std::endl;
            std::cout << "Vous avez gagne " << m_activeQuetes[i]->getGold() << " pieces d'or" << std::endl;
            m_activeQuetes[i]->setActive(false);
            m_activeQuetes.erase(m_activeQuetes.begin() + i);
            m_quetes[i]->setFinish(true);

//            playerLevelUp();
        }
    }
}

void Game::playerLevelUp() {
    for (int i = 0; i < m_quetes.size(); i++) {
        if (!m_quetes[i]->getActive() && !m_quetes[i]->getFinish() && m_player->getCharacterPtr()->getExperience() >= m_quetes[i]->getRequireExp()) {
            m_quetes[i]->setActive(true);
            m_activeQuetes.push_back(m_quetes[i]);
            std::cout << "Vous avez debloque la quete : " << m_quetes[i]->getName() << " (" << m_quetes[i]->getDescription() << ")" << std::endl;
            std::cout << m_player->getCharacterPtr()->getExperience() << " / " << m_quetes[i]->getRequireExp() << std::endl;
        }
    }
}

void Game::setRunning(bool isRunning) {
    m_isRunning = isRunning;
}

Player *Game::getPlayerPtr() const {
    return m_player;
}

Game &Game::getInstance() {
    static Game instance;
    return instance;
}
