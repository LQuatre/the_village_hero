//
// Created by admin on 30/11/2023.
//

#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::setCharacter(const Character& character) {
    m_character = character;
}

Character Player::getCharacter() const {
    return m_character;
}

Character* Player::getCharacterPtr() {
    return &m_character;
}

void Player::setAdmin(bool admin) {
    m_admin = admin;
    std::cout << "Admin: " << m_admin << std::endl;
}

bool Player::getAdmin() const {
    return m_admin;
}
