//
// Created by admin on 30/11/2023.
//

#include "Mine.h"
Mine::Mine(std::string name, int givingGold, std::vector<Monster *> monsters) : Building(name) {
    m_givingGold = givingGold;
    m_monsters = monsters;
}

Mine::~Mine() {

}

void Mine::setGiveGold(int gold) {
    m_givingGold = gold;
}

void Mine::setMonster(Monster *monster) {
    m_monster = monster;
}

void Mine::addMonster(Monster *monster) {
    m_monsters.push_back(monster);
}

void Mine::delMonster(Monster *monster) {
    for (int i = 0; i < m_monsters.size(); ++i) {
        if (m_monsters[i] == monster) {
            m_monsters.erase(m_monsters.begin() + i);
        }
    }
}