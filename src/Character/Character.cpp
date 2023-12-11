//
// Created by admin on 30/11/2023.
//

#include "Character.h"
#include <iostream>

Character::Character(int health, int gold, Weapon* weapon) : Name() {
    m_health = health;
    m_gold = gold;
    m_weapon = weapon;
}

Character::~Character() {}

void Character::setHealth(int health) {
    m_health = health;
}

int Character::getHealth() const {
    return m_health;
}

void Character::heal(int health) {
    m_health += health;
}

void Character::takeDamage(int damage) {
    m_health -= damage;
}

void Character::setGold(int gold) {
    m_gold = gold;
}

void Character::addGold(int gold) {
    m_gold += gold;
}

void Character::removeGold(int gold) {
    m_gold -= gold;
}

int Character::getGold() const {
    return m_gold;
}

void Character::setWeapon(Weapon* weapon) {
    m_weapon = weapon;
}

Weapon* Character::getWeapon() const {
    return m_weapon;
}

void Character::addWeapon(Weapon *weapon) {
    m_weapons.push_back(weapon);
}

void Character::setExperience(int experience) {
    experience = experience;
}

int Character::getExperience() const {
    return experience;
}

void Character::addExperience(int experience) {
    experience += experience;
}

