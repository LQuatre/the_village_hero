//
// Created by admin on 30/11/2023.
//

#include "Weapon.h"

Weapon::Weapon(int price, int damage) : Name() {
    m_price = price;
    m_damage = damage;
}

Weapon::~Weapon() {

}

int Weapon::getPrice() const {
    return m_price;
}

void Weapon::setPrice(int price) {
    m_price = price;
}

int Weapon::getDamage() const {
    return m_damage;
}

void Weapon::setDamage(int damage) {
    m_damage = damage;
}