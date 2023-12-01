//
// Created by admin on 30/11/2023.
//

#include "../H/Village.h"

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