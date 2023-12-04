//
// Created by admin on 30/11/2023.
//

#include "../dasmig/namegen.hpp"
#include "../H/Village.h"
#include "../H/Monster.h"
#include "../H/Weapon.h"
#include <iostream>


// For convenience.
using ng = dasmig::ng;


Village::Village(std::string name) {
    this->m_name = name;
    std::cout << "Village " << this->m_name << " created" << std::endl;
 }

Village::~Village() {
    std::cout << "Village " << this->m_name << " destroyed" << std::endl;
}

void Village::setName(std::string name) {
    this->m_name = name;
}

std::string Village::getName() const {
    return this->m_name;
}

void Village::addBuilding(Building *building) {
    this->m_buildings.push_back(building);
}

std::vector<Building*> Village::getBuildings() const {
    return this->m_buildings;
}

std::string generateName() {
    ng::instance().load("../resources");
    std::wstring franch_name = ng::instance().get_name(ng::gender::m, ng::culture::french);
    std::wcout << franch_name << std::endl;
    std::string name = std::string(franch_name.begin(), franch_name.end());
    return name;
}

void Village::generateBuildings() {
    int numberMaxForEachBuildings = 3;
    int numberMaxBuildings = 6;

    for (int i = 0; i < rand() % numberMaxBuildings + 1; i++) {
        int randomValue = rand() % numberMaxForEachBuildings + 1;
        printf("Random Value: %d\n", randomValue);

        if (i < randomValue) {
            this->m_buildings.push_back(new Auberge(generateName(), rand() % 100 + 1, rand() % 100 + 1));
        } else if (i < randomValue * 2) {
            std::vector<Monster*> monsters;
            monsters.push_back(new Monster(generateName(), rand() % 100 + 1, rand() % 100 + 1));
            this->m_buildings.push_back(new Mine(generateName(), rand() % 100 + 1, monsters));
        } else if (i < randomValue * 3) {
            std::vector<Weapon*> weapons;
            weapons.push_back(new Weapon(generateName(), rand() % 100 + 1, rand() % 100 + 1));
            this->m_buildings.push_back(new Dealer(generateName(), weapons));
        }
    }
}


