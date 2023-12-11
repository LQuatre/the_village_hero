//
// Created by admin on 30/11/2023.
//

#include "Building.h"

Building::Building() : Name() {
}

Building::Building(const std::string &name) : Name(name) {
}


Building::~Building() {

}

std::string Building::getType() const {
//    found type in Name
    std::string myName = getName();
    std::vector<std::string> types = {"Auberge", "Mine", "Dealer"};
    for (const auto & type : types) {
        if (myName.find(type) != std::string::npos) {
            return type;
        }
    }
}
