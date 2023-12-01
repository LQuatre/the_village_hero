//
// Created by admin on 30/11/2023.
//

#include "../H/Game.h"
#include "../H/Character.h"
#include "../H/Player.h"
#include "../H/Village.h"

Game::Game() {
    this->m_village = new Village("Konoha");
    this->m_villages.push_back(this->m_village);

    Character thisChar("Milo", 100, 10, nullptr);
    this->m_player = new Player(thisChar);
    this->m_players.push_back(this->m_player);
}

Game::~Game() {

}

bool Game::IsRunning() const {
    return m_isRunning;}

void Game::start() {
    m_isRunning = true;

    std::cout << "Bienvenue dans le jeu du Hero du village !" << std::endl;
    std::cout << "Vous etes dans le village de " << this->m_village->getName() << std::endl;
    std::cout << "Vous etes " << this->m_player->getCharacter().getName() << std::endl;
    Character deuxiemeJoueur("Fabrice", 100, 10, nullptr);
    Player deuxiemePlayer(deuxiemeJoueur);
    this->m_players.push_back(&deuxiemePlayer);
    std::cout << "Vous avez " << this->m_players[1]->getCharacter().getName() << " en second joueur" << std::endl;

    this->run();
}

void Game::run() {
    while (this->IsRunning()) {

    }
}