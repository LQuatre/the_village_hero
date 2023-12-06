//
// Created by admin on 30/11/2023.
//

#include "Player.h"

Player::Player(const Character& character) {
    this->m_character = character;
}

Player::~Player() {}

void Player::setCharacter(const Character& character) {
    this->m_character = character;
}

Character Player::getCharacter() const {
    return this->m_character;
}

const Character *Player::getCharacterPtr() {
    return &this->m_character;
}
