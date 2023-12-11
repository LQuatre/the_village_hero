//
// Created by admin on 30/11/2023.
//


#include "Village.h"
#include <iostream>


Village::Village() : Name() {
//    std::cout << "Village " << getName() << " created" << std::endl;
 }

Village::~Village() {
//    std::cout << "Village " << getName() << " destroyed" << std::endl;
}

void Village::addBuilding(Building *building) {
    m_buildings.push_back(building);
}

std::vector<Building*> Village::getBuildings() const {
    return m_buildings;
}

std::vector<Building*> Village::getBuildingsByType(std::string type) {
    std::vector<Building*> buildings;
    for (int i = 0; i < m_buildings.size(); ++i) {
        if (m_buildings[i]->getType() == type) {
            buildings.push_back(m_buildings[i]);
        }
    }
    if (buildings.empty()) {
        std::cout << "No building of type " << type << " found" << std::endl;
    }
    return buildings;
}

int randomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void Village::genBuildingByType(std::string type) {
    if (type == "Auberge") {
        Auberge *auberge = new Auberge("", rand() % 100 + 1, rand() % 100 + 1);
        auberge->setName(auberge->generateName() + "'s Auberge");
        m_buildings.push_back(auberge);
    } else if (type == "Mine") {
        std::vector<Monster*> monsters;
        Monster *monster = new Monster(rand() % 100 + 1, rand() % 100 + 1);
        monsters.push_back(monster);
        Mine *mine = new Mine("", rand() % 100 + 1, monsters);
        mine->setName(mine->generateName() + "'s Mine");
        m_buildings.push_back(mine);
    } else if (type == "Dealer") {
        std::vector<Weapon*> weapons;
        Weapon *weapon = new Weapon(rand() % 100 + 1, rand() % 100 + 1);
        weapons.push_back(weapon);
        Dealer *dealer = new Dealer("", weapons);
        dealer->setName(dealer->generateName() + "'s Dealer");
        m_buildings.push_back(dealer);
    }
}

void Village::generateBuildings() {
    const int numberMaxForEachBuildings = 3;
    const int numberMaxBuildings = 8;

    for (int i = 0; i < numberMaxBuildings; ++i) {
        int randomValue = randomNumber(1, numberMaxForEachBuildings);

        if (i < randomValue && i < numberMaxBuildings) {
            genBuildingByType("Auberge");
        } else if (i < randomValue * 2 && i < numberMaxBuildings) {
            genBuildingByType("Mine");
        } else if (i < randomValue * 3 && i < numberMaxBuildings) {
            genBuildingByType("Dealer");
        }
    }
    if (getBuildingsByType("Auberge").empty()) {
        genBuildingByType("Auberge");
    }
    if (getBuildingsByType("Mine").empty()) {
        genBuildingByType("Mine");
    }
    if (getBuildingsByType("Dealer").empty()) {
        genBuildingByType("Dealer");
    }
}


void Village::displayBuildings() {
    std::cout << "Buildings in " << getName() << " :" << std::endl;
    for (int i = 0; i < m_buildings.size(); ++i) {
        std::cout << "Building " << i+1 << " : " << m_buildings[i]->getName() << std::endl;
    }
}