//
// Created by admin on 30/11/2023.
//

#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::setCharacter(const Character& character) {
    this->m_character = character;
}

Character Player::getCharacter() const {
    return this->m_character;
}

Character* Player::getCharacterPtr() {
    return &this->m_character;
}

void Player::setAdmin(bool admin) {
    this->m_admin = admin;
    std::cout << "Admin: " << this->m_admin << std::endl;
}

bool Player::getAdmin() const {
    return this->m_admin;
}
