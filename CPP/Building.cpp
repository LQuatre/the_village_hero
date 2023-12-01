//
// Created by admin on 30/11/2023.
//

#include "../H/Building.h"

Building::Building(std::string name) {
    this->m_name = name;
}

Building::~Building() {

}

void Building::setName(const std::string name) {
    this->m_name = name;
}

std::string Building::getName() const {
    return this->m_name;
}