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

void Village::generateBuildings() {
    const int numberMaxForEachBuildings = 3;
    const int numberMaxBuildings = 6;

    for (int i = 0; i < numberMaxBuildings; ++i) {
        int randomValue = rand() % numberMaxForEachBuildings + 1;

        if (i < randomValue && i < numberMaxBuildings) {
            auto *auberge = new Auberge("", rand() % 100 + 1, rand() % 100 + 1);
            auberge->setName("Auberge " + auberge->generateName());
            this->m_buildings.push_back(auberge);
        } else if (i < randomValue * 2 && i < numberMaxBuildings) {
            std::vector<Monster*> monsters;
            auto *monster = new Monster(rand() % 100 + 1, rand() % 100 + 1);
            monsters.push_back(monster);
            auto *mine = new Mine("", rand() % 100 + 1, monsters);
            mine->setName("Mine " + mine->generateName());
            this->m_buildings.push_back(mine);
        } else if (i < randomValue * 3 && i < numberMaxBuildings) {
            std::vector<Weapon*> weapons;
            auto *weapon = new Weapon(rand() % 100 + 1, rand() % 100 + 1);
            weapons.push_back(weapon);
            auto *dealer = new Dealer("", weapons);
            dealer->setName("Dealer " + dealer->generateName());
            this->m_buildings.push_back(dealer);
        }
    }
}


void Village::displayBuildings() {
    std::cout << "Buildings in " << this->getName() << " :" << std::endl;
    for (int i = 0; i < this->m_buildings.size(); ++i) {
        std::cout << "Building " << i << " : " << this->m_buildings[i]->getName() << std::endl;
    }
}