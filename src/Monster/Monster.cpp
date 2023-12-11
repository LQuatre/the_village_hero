//
// Created by admin on 30/11/2023.
//

#include "Monster.h"

Monster::Monster(int damage, int health) : Name() {
    m_damage = damage;
    m_health = health;
}

Monster::~Monster() {

}

void Monster::takeDamage(int damage) {
    m_health -= damage;
}
