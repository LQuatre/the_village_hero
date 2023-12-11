//
// Created by LQuatre on 07/12/2023.
//

#include "Quete.h"

Quete::Quete(std::string name, std::string description, std::string action, int requireExp, int exp, int gold) : Name(name) {
    m_description = description;
    m_requireExp = requireExp;
    m_action = action;
    m_exp = exp;
    m_gold = gold;
}

Quete::~Quete() {}

std::string Quete::getDescription() const {
    return m_description;
}

std::string Quete::getAction() const {
    return m_action;
}

int Quete::getExp() const {
    return m_exp;
}

int Quete::getGold() const {
    return m_gold;
}

void Quete::setActive(bool active) {
    m_active = active;
}

bool Quete::getActive() {
    return m_active;
}

int Quete::getRequireExp() const {
    return m_requireExp;
}

bool Quete::getFinish() {
    return m_finish;
}

void Quete::setFinish(bool finish) {
    m_finish = finish;
}
