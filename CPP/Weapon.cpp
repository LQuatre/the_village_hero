//
// Created by admin on 30/11/2023.
//

#include "../H/Weapon.h"

Weapon::Weapon(const std::string &name, int price, int damage) {
    this->m_name = name;
    this->m_price = price;
    this->m_damage = damage;
}

Weapon::~Weapon() {

}

std::string Weapon::getName() {
    return m_name;
}

void Weapon::setName(const std::string &name) {
    m_name = name;
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