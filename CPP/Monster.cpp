//
// Created by admin on 30/11/2023.
//

#include "../H/Monster.h"

Monster::Monster(std::string name, int damage, int health) {
    this->m_name = name;
    this->m_damage = damage;
    this->m_health = health;
}

Monster::~Monster() {

}

void Monster::takeDamage(int damage) {
    this->m_health -= damage;
}
