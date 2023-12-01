//
// Created by admin on 30/11/2023.
//

#include "../H/Character.h"
#include <iostream>

Character::Character(std::string name, int health, int gold, Weapon* weapon) {
    this->m_name = name;
    this->m_health = health;
    this->m_gold = gold;
    this->m_weapon = weapon;
}

Character::~Character() {}

void Character::setName(std::string name) {
    this->m_name = name;
}

std::string Character::getName() const {
    return this->m_name;
}

void Character::setHealth(int health) {
    this->m_health = health;
}

int Character::getHealth() const {
    return this->m_health;
}

void Character::heal(int health) {
    this->m_health += health;
}

void Character::takeDamage(int damage) {
    this->m_health -= damage;
}

void Character::setGold(int gold) {
    this->m_gold = gold;
}

void Character::addGold(int gold) {
    this->m_gold += gold;
}

void Character::removeGold(int gold) {
    this->m_gold -= gold;
}

int Character::getGold() const {
    return this->m_gold;
}

void Character::setWeapon(Weapon* weapon) {
    this->m_weapon = weapon;
}

Weapon* Character::getWeapon() const {
    return this->m_weapon;
}

void Character::addWeapon(Weapon *weapon) {
    this->m_weapons.push_back(weapon);
}