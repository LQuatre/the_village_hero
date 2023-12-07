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

bool ativatedFreeGold = false;

Game::Game() {
    this->m_village = new Village();
    this->m_village->setName("konoha");
    this->m_village->generateBuildings();
    this->m_villages.push_back(this->m_village);

    Character& thisChar = *new Character(100, 10, nullptr);
    this->m_characters.push_back(&thisChar);
    this->m_player = new Player();
    this->m_player->setCharacter(thisChar);
    this->m_players.push_back(this->m_player);

    Quete& quete1 = *new Quete("quete1", "quete1", "enter  dealer", 1, 1, 5);
    this->m_quetes.push_back(&quete1);
}

Game::~Game() {

}

bool Game::IsRunning() const {
    return m_isRunning;
}

void Game::start() {
    m_isRunning = true;

    this->clearTerminal();

    std::cout << "Bienvenue dans le jeu du Hero du village !" << std::endl;
    std::cout << "Vous etes dans le village de " << this->m_village->getName() << std::endl;
    std::cout << "Vous etes " << this->m_player->getCharacter().getName() << std::endl;
    std::cout << "Vous avez " << this->m_player->getCharacter().getHealth() << " points de vie" << std::endl;
    std::cout << "Vous avez " << this->m_player->getCharacter().getGold() << " pieces d'or" << std::endl;

    playerLevelUp();
    this->run();
}

void Game::run() {
    while (this->IsRunning()) {
        if (this->m_player->getCharacter().getHealth() <= 0) {
            std::cout << "Vous etes mort" << std::endl;
            this->m_isRunning = false;
        }
        if (this->m_player->getCharacter().getGold() > 20) {
            playerAction("player have >20 gold");
        }
        this->Input();
    }
}

void Game::clearTerminal() {
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
    } else if (input == "code") {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

        int c;
        while ((c = std::cin.get()) != '\n' && c != EOF);

        std::string s;
        getline(std::cin, s);

        if (s == "FreeGold" && !ativatedFreeGold) {
            ativatedFreeGold = true;
            this->m_player->getCharacterPtr()->addGold(9989);
            std::cout << "Vous avez actuellement : " << this->m_player->getCharacter().getGold() << " pieces d'or" << std::endl;
        } else {
            std::cout << "Vous avez deja utilise ce code" << std::endl;
        }
    } else if (input == "admin") {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

        int c;
        while ((c = std::cin.get()) != '\n' && c != EOF);

        std::string s;
        getline(std::cin, s);

        if (s == "RocketLeague2023") {
            this->m_player->setAdmin(true);
        }
    } else if (input == "addGold" || input == "removeGold" || input == "setGold" || input == "setHealth" || input == "heal") {
        if (this->m_player->getAdmin()) {
            if (input == "addGold") {
                std::cout << "How many gold do you want to add ?" << std::endl;
                int gold;
                std::cin >> gold;
                this->m_player->getCharacterPtr()->addGold(gold);
            } else if (input == "removeGold") {
                std::cout << "How many gold do you want to remove ?" << std::endl;
                int gold;
                std::cin >> gold;
                this->m_player->getCharacterPtr()->removeGold(gold);
            } else if (input == "setGold") {
                std::cout << "How many gold do you want to set ?" << std::endl;
                int gold;
                std::cin >> gold;
                this->m_player->getCharacterPtr()->setGold(gold);
            } else if (input == "setHealth") {
                std::cout << "How many health do you want to set ?" << std::endl;
                int health;
                std::cin >> health;
                this->m_player->getCharacterPtr()->setHealth(health);
            } else if (input == "heal") {
                std::cout << "How many health do you want to add ?" << std::endl;
                int health;
                std::cin >> health;
                this->m_player->getCharacterPtr()->heal(health);
            }
        } else {
            std::cout << "You are not an admin" << std::endl;
        }
    } else {
        std::cout << "Command not found" << std::endl;
    }
}




void Game::help() {
    std::cout << "Command list available:" << std::endl;
    std::cout << "help" << std::endl;
    std::cout << "quit" << std::endl;
    if (this->m_player->getAdmin()) {
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
    for (int i = 0; i < this->m_quetes.size(); i++) {
        if (action == this->m_activeQuetes[i]->getAction()) {
            std::cout << "Vous avez termine la quete : " << this->m_activeQuetes[i]->getName() << std::endl;
            this->m_player->getCharacterPtr()->addExperience(this->m_activeQuetes[i]->getExp());
            this->m_player->getCharacterPtr()->addGold(this->m_activeQuetes[i]->getGold());
            std::cout << "Vous avez gagne " << this->m_activeQuetes[i]->getExp() << " points d'experience" << std::endl;
            std::cout << "Vous avez gagne " << this->m_activeQuetes[i]->getGold() << " pieces d'or" << std::endl;
            this->m_activeQuetes[i]->setActive(false);
            this->m_activeQuetes.erase(this->m_activeQuetes.begin() + i);
            this->m_quetes[i]->setFinish(true);

//            playerLevelUp();
        }
    }
}

void Game::playerLevelUp() {
    for (int i = 0; i < this->m_quetes.size(); i++) {
        if (!this->m_quetes[i]->getActive() && !this->m_quetes[i]->getFinish() && this->m_player->getCharacterPtr()->getExperience() >= this->m_quetes[i]->getRequireExp()) {
            this->m_quetes[i]->setActive(true);
            this->m_activeQuetes.push_back(this->m_quetes[i]);
            std::cout << "Vous avez debloque la quete : " << this->m_quetes[i]->getName() << std::endl;
            std::cout << this->m_player->getCharacterPtr()->getExperience() << " / " << this->m_quetes[i]->getRequireExp() << std::endl;
        }
    }
}
