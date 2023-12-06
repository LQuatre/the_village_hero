//
// Created by admin on 30/11/2023.
//

#include "Mine.h"
Mine::Mine(std::string name, int givingGold, std::vector<Monster *> monsters) : Building(name) {
    this->m_givingGold = givingGold;
    this->m_monsters = monsters;
}

Mine::~Mine() {

}

void Mine::setGiveGold(int gold) {
    this->m_givingGold = gold;
}

void Mine::setMonster(Monster *monster) {
    this->m_monster = monster;
}

void Mine::addMonster(Monster *monster) {
    this->m_monsters.push_back(monster);
}

void Mine::delMonster(Monster *monster) {
    for (int i = 0; i < this->m_monsters.size(); ++i) {
        if (this->m_monsters[i] == monster) {
            this->m_monsters.erase(this->m_monsters.begin() + i);
        }
    }
}