//
// Created by LQuatre on 07/12/2023.
//

#include "Quete.h"

Quete::Quete(std::string name, std::string description, std::string action, int requireExp, int exp, int gold) : Name(name) {
    this->m_description = description;
    this->m_requireExp = requireExp;
    this->m_action = action;
    this->m_exp = exp;
    this->m_gold = gold;
}

Quete::~Quete() {}

std::string Quete::getDescription() const {
    return this->m_description;
}

std::string Quete::getAction() const {
    return this->m_action;
}

int Quete::getExp() const {
    return this->m_exp;
}

int Quete::getGold() const {
    return this->m_gold;
}

void Quete::setActive(bool active) {
    this->m_active = active;
}

bool Quete::getActive() {
    return this->m_active;
}

int Quete::getRequireExp() const {
    return this->m_requireExp;
}

bool Quete::getFinish() {
    return this->m_finish;
}

void Quete::setFinish(bool finish) {
    this->m_finish = finish;
}
