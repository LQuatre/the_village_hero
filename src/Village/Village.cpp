//
// Created by admin on 30/11/2023.
//


#include "Village.h"
#include <iostream>


Village::Village() : Name() {
//    std::cout << "Village " << this->getName() << " created" << std::endl;
 }

Village::~Village() {
//    std::cout << "Village " << this->getName() << " destroyed" << std::endl;
}

void Village::addBuilding(Building *building) {
    this->m_buildings.push_back(building);
}

std::vector<Building*> Village::getBuildings() const {
    return this->m_buildings;
}

int randomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void Village::generateBuildings() {
    const int numberMaxForEachBuildings = 3;
    const int numberMaxBuildings = 8;

    for (int i = 0; i < numberMaxBuildings; ++i) {
        int randomValue = randomNumber(1, numberMaxForEachBuildings);

        if (i < randomValue && i < numberMaxBuildings) {
            auto *auberge = new Auberge("", rand() % 100 + 1, rand() % 100 + 1);
            auberge->setName(auberge->generateName() + "'s Auberge");
            this->m_buildings.push_back(auberge);
        } else if (i < randomValue * 2 && i < numberMaxBuildings) {
            std::vector<Monster*> monsters;
            auto *monster = new Monster(rand() % 100 + 1, rand() % 100 + 1);
            monsters.push_back(monster);
            auto *mine = new Mine("", rand() % 100 + 1, monsters);
            mine->setName(mine->generateName() + "'s Mine");
            this->m_buildings.push_back(mine);
        } else if (i < randomValue * 3 && i < numberMaxBuildings) {
            std::vector<Weapon*> weapons;
            auto *weapon = new Weapon(rand() % 100 + 1, rand() % 100 + 1);
            weapons.push_back(weapon);
            auto *dealer = new Dealer("", weapons);
            dealer->setName(dealer->generateName() + "'s Dealer");
            this->m_buildings.push_back(dealer);
        }
    }
}


void Village::displayBuildings() {
    std::cout << "Buildings in " << this->getName() << " :" << std::endl;
    for (int i = 0; i < this->m_buildings.size(); ++i) {
        std::cout << "Building " << i+1 << " : " << this->m_buildings[i]->getName() << std::endl;
    }
}