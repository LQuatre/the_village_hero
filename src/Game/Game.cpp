//
// Created by admin on 30/11/2023.
//

#include "Game.h"
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Village/Village.h"

Game::Game() {
    this->m_village = new Village();
    this->m_village->setName("konoha");
    this->m_village->generateBuildings();
    this->m_village->displayBuildings();
    this->m_villages.push_back(this->m_village);

    Character thisChar(100, 10, nullptr);
    this->m_characters.push_back(&thisChar);
    this->m_player = new Player(thisChar);
    this->m_players.push_back(this->m_player);
}

Game::~Game() {

}

bool Game::IsRunning() const {
    return m_isRunning;}

void Game::start() {
    m_isRunning = true;

    this->ClearTerminal();

    std::cout << "Bienvenue dans le jeu du Hero du village !" << std::endl;
    std::cout << "Vous etes dans le village de " << this->m_village->getName() << std::endl;
    std::cout << "Vous etes " << this->m_player->getCharacter().getName() << std::endl;
    std::cout << "Vous avez " << this->m_player->getCharacter().getHealth() << " points de vie" << std::endl;
    std::cout << "Vous avez " << this->m_player->getCharacter().getGold() << " pieces d'or" << std::endl;
    this->run();
}

void Game::run() {
    while (this->IsRunning()) {
        this->Input();
    }
}

void Game::ClearTerminal() {
//    std::cout << "\x1B[2J\x1B[H";
}

void Game::Input() {
    std::cout << std::endl << "What do you want to do ?" << std::endl;

    std::string input;
    std::cin >> input;

    if (input == "quit") {
        std::cout << "You quit the game" << std::endl;
        this->m_isRunning = false;
    } else if (input == "help") {
        this->help();
    } else {
        std::cout << "Command not found" << std::endl;
    }
}

void Game::help() {
    std::cout << "Command list available:" << std::endl;
    std::cout << "help" << std::endl;
    std::cout << "quit" << std::endl;
}
