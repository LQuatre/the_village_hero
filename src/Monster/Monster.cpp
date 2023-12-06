//
// Created by admin on 30/11/2023.
//

#include "Monster.h"

Monster::Monster(int damage, int health) : Name() {
    this->m_damage = damage;
    this->m_health = health;
}

Monster::~Monster() {

}

void Monster::takeDamage(int damage) {
    this->m_health -= damage;
}
